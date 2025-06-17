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
	int	status;
	int	pid;
	int	cmd_count;

	cmd_count = len_cmd(start_cmd);
	while (cmd_count > 0)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
			handle_child_status(cont, pid, status);
		cmd_count--;
	}
}

static int	handle_single_builtin(t_controller *cont, t_cmd *cmd)
{
	if (is_builtin(cmd) && !cmd->next)
	{
		return (prepare_builtin(cont, cmd));
	}
	return (-1);
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
	if (!cmd)
		return (1);
	builtin_result = handle_single_builtin(cont, cmd);
	if (builtin_result != -1)
		return (builtin_result);
	exec_pipeline(cont);
	wait_process(cont, cont->cmdlist.cmds);
	return (cont->excode);
}
