/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:47:28 by samfighter        #+#    #+#             */
/*   Updated: 2025/06/02 16:49:12 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void		built(int *pip, t_cmd *cmd, t_controller *cont)
{
	close(pip[0]);
	if (cmd->fd_out < 0 && cmd->next != cont->cmdlist.cmds)
		cmd->fd_out = pip[1];
	else
		close(pip[1]);
	prepare_builtin(cont, cmd);
}

static void  exec_child(t_controller *cont, t_cmd *cmd, int *pip)
{
  char  *path;

  path = NULL;
  if (is_builtin(cmd))
	  built(pip, cmd, cont);
  else if (check_cmd(path, cont))
  {
	redir_in_out(cont, cmd, pip);
	rl_clear_history();
	execve(path, cmd->cmd_args, cont->env);
  }
  if (path)
	  free(path);
}

static void		exec_parent(t_cmd *cmd, int *pip)
{
	close(pip[1]);
	if (cmd->fd_inf >= 0)
		close(cmd->fd_inf);
	if (cmd->fd_inf == -2)
		cmd->fd_inf = pip[0];
	if (cmd->next && cmd->next->fd_inf == -2)
		cmd->fd_inf = pip[0];
	else
		close(pip[0]);
}

static void		exec_cmd(t_controller *cont, t_cmd *cmd, int *pip)
{
	g_sig = fork();
	if (g_sig < 0)
		return ;
	else if (!g_sig)
	{
	  if(cmd->cmd_args && cmd->cmd_args[0])
			exec_child(cont, cmd, pip);
	  else
			perror(cmd->cmd_args[0]);
	}
	else
		exec_parent(cmd, pip);
}

int		exec(t_controller *cont)
{
	t_cmd	*cmd;
	int		*pip;

	pip = cont->pip;
	cmd = cont->cmdlist.cmds;
	if (is_builtin(cmd))
		return (prepare_builtin(cont, cmd));
	if (pipe(pip) == -1)
		return (1);
	exec_cmd(cont, cmd, pip);
	cmd = cmd->next;
	while (cmd != cont->cmdlist.cmds)
	{
		if (pipe(pip) == -1)
		  return (-1);
		exec_cmd(cont, cmd, pip);
		cmd = cmd->next;
	}
	return (0);
}
