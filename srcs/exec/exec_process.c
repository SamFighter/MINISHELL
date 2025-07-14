/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:36:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/10 14:41:39 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	free_contnpath(t_controller *cont, char	**args)
{
	utl_super_free((void **) args);
	controller_free(cont);
}

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
		controller_free(cont);
		exit(127);
	}
	args = str_rarrdup_nset(cmd->args, cmd->str_cmd);
	execve(path, args, cont->env);
	free_contnpath(cont, args);
	free(path_env);
	free(path);
	controller_free(cont);
	exit(126);
}

static void	exec_child(t_controller *cont, t_cmd *cmd, int *pip)
{
	int	result;

	result = 0;
	if (redir_in_out(cmd, pip) == -1)
	{
		controller_free(cont);
		exit(1);
	}
	if (is_builtin(cmd))
	{
		result = prepare_builtin(cont, cmd);
		controller_free(cont);
		exit(result);
	}
	exec_external_cmd(cont, cmd);
}

static void	exec_parent(t_cmd *cmd, int *pip)
{
	if (pip)
	{
		close(pip[1]);
		if (cmd->next)
			cmd->next->fd_inf = pip[0];
		else
			close(pip[0]);
	}
	if (cmd->fd_inf > 2)
		close(cmd->fd_inf);
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
}

void	exec_cmd(t_controller *cont, t_cmd *cmd, int *pip)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
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
