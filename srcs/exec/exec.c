/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:47:28 by samfighter        #+#    #+#             */
/*   Updated: 2025/06/17 11:06:01 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_exec_error(char *path, char *path_env, int *pip)
{
	if (pip)
	{
		close(pip[0]);
		close(pip[1]);
	}
	if (path)
		free(path);
	if (path_env)
		free(path_env);
	exit(127);
}

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

static int	handle_single_builtin(t_controller *cont, t_cmd *cmd)
{
	int	stdin_copy;
	int	stdout_copy;
	int	result;

	if (!is_builtin(cmd) || cmd->next)
		return (-1);
	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	if (redir_in_out(cmd, NULL) == -1)
	{
		dup2(stdin_copy, STDIN_FILENO);
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdin_copy);
		close(stdout_copy);
		return (-1);
	}
	result = prepare_builtin(cont, cmd);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	close(stdin_copy);
	close(stdout_copy);
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
	return (cont->excode);
}
