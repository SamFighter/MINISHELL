/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:21:06 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/27 16:08:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    redir_in_out(t_controller *cont, t_cmd *cmd, int *pipe)
{
	close(pip[0]);
	if (cmd->fd_inf >= 0)
	{
		dup2(cmd->fd_inf, 0);
		close(cmd->fd_inf);
	}
	if (cmd->fd_out >= 0)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
	else if (cmd->next != data->cmdlist->cmds)
		dup2(pip[1], 1);
	close(pip[1]);
}
