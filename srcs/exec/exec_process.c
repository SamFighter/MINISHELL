/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:36:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/19 14:24:16 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	exec_external_cmd(t_controller *cont, t_cmd *cmd)
{
	char	*path;
	char	*path_env;
	char	**args;

	path_env = search_envp("PATH", cont->env);
	path = get_path(path_env, cmd);
	if (!path)
	{
		fd_printf(2, "minihell: %s: command not found\n", cmd->str_cmd);
		free(path_env);
		cleanup_and_exit(cont, 127);
	}
	args = str_rarrdup_nset(cmd->args, cmd->str_cmd);
	execve(path, args, cont->env);
	utl_super_free((void **)args);
	free(path_env);
	free(path);
	cleanup_and_exit(cont, 126);
}

static void	exec_child(t_controller *cont, t_cmd *cmd, int *pip)
{
	int	result;

	if (redir_in_out(cmd, pip) == -1)
		cleanup_and_exit(cont, 1);
	if (is_builtin(cmd))
	{
		close(0);
		result = exec_builtins(cont, cmd->str_cmd, cmd->args);
		cleanup_and_exit(cont, result);
	}
	exec_external_cmd(cont, cmd);
}

static void	exec_parent(t_cmd *cmd, int *pip)
{
	if (pip)
	{
		close(pip[1]);
		if (cmd->next)
		{
			if (cmd->next->fd_inf >= 0)
				close(cmd->next->fd_inf);
			cmd->next->fd_inf = pip[0];
		}
		else
			close(pip[0]);
	}
	cleanup_cmd_fds(cmd);
}

void	exec_cmd(t_controller *cont, t_cmd *cmd, int *pip)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		if (pip)
		{
			safe_close(pip[0]);
			safe_close(pip[1]);
		}
		return ;
	}
	if (pid == 0)
		exec_child(cont, cmd, pip);
	else
	{
		cmd->pid = pid;
		exec_parent(cmd, pip);
	}
}
