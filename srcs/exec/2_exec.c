/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_exec.c                                           :+:      :+:    :+:   */
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
	if (cmd->fd_out < 0 && cmd->next != cont->cmdlist->cmds)
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
  else if (check_cmd(&path, cont))
  {
	redir_in_out(cont, cmd, pip);
	rl_clear_history();
	execve(path, cmd->cmd_args, cont->env);
  }
  if (path)
	  free(path);
}

static void		exec_cmd(t_controller *cont, t_cmd	cmd, int *pip)
{
	g_sig = fork();
	if (g_sig < 0)
		perror(g_sig);
	else if (!g_sig)
	{
	  if(cmd->cmd_args && cmd->cmd_args[0])
			exec_child(cont, cmd, pip);
	  else
			perror(cmd->cmd_args);
	}
	else
		
}
