/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:47:28 by samfighter        #+#    #+#             */
/*   Updated: 2025/07/16 09:55:07 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	wait_process(t_controller *cont, t_cmd *start_cmd)
{
	int		status;
	int		pid;
	int		cmd_count;
	int		last_pid;
	t_cmd	*tmp;

	tmp = start_cmd;
	last_pid = -1;
	while (tmp)
	{
		if (tmp->pid > 0)
			last_pid = tmp->pid;
		tmp = tmp->next;
	}
	cmd_count = len_cmd(start_cmd);
	while (cmd_count > 0)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
			handle_child_status(cont, pid, status, last_pid);
		cmd_count--;
	}
}

static int	setup_builtin_fds(t_cmd *cmd, int *stdin_backup, int *stdout_backup)
{
	*stdin_backup = dup(STDIN_FILENO);
	*stdout_backup = dup(STDOUT_FILENO);
	if (*stdin_backup == -1 || *stdout_backup == -1)
		return (-1);
	return (redir_in_out(cmd, NULL));
}

static int	handle_single_builtin(t_controller *cont, t_cmd *cmd)
{
	int	stdin_backup;
	int	stdout_backup;
	int	result;

	if (!is_builtin(cmd) || cmd->next)
		return (-1);
	if (setup_builtin_fds(cmd, &stdin_backup, &stdout_backup) == -1)
	{
		safe_close(stdin_backup);
		safe_close(stdout_backup);
		return (-1);
	}
	if (str_cmp("exit", cmd->str_cmd) == 0)
	{
		close(stdin_backup);
		close(stdout_backup);
	}
	result = exec_builtins(cont, cmd->str_cmd, cmd->args);
	dup2(stdin_backup, STDIN_FILENO);
	dup2(stdout_backup, STDOUT_FILENO);
	safe_close(stdin_backup);
	safe_close(stdout_backup);
	cleanup_cmd_fds(cmd);
	return (result);
}

static void	exec_pipeline(t_controller *cont)
{
	t_cmd	*cmd;
	int		pip[2];
	int		*current_pipe;

	cmd = cont->cmdlist.cmds;
	while (cmd)
	{
		current_pipe = NULL;
		if (cmd->next)
		{
			if (pipe(pip) == -1)
			{
				perror("pipe");
				cont->excode = 1;
				cleanup_all_fds(cont->cmdlist.cmds);
				return ;
			}
			current_pipe = pip;
		}
		exec_cmd(cont, cmd, current_pipe);
		cmd = cmd->next;
	}
}

int	exec(t_controller *cont)
{
	t_cmd	*cmd;
	int		builtin_result;

	cmd = cont->cmdlist.cmds;
	if (!cmd || !cmd->str_cmd)
	{
		cont->excode = 0;
		return (0);
	}
	builtin_result = handle_single_builtin(cont, cmd);
	if (builtin_result != -1)
	{
		cont->excode = builtin_result;
		return (builtin_result);
	}
	exec_pipeline(cont);
	wait_process(cont, cont->cmdlist.cmds);
	cleanup_all_fds(cont->cmdlist.cmds);
	return (cont->excode);
}
