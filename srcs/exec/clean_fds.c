/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:21:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/15 15:42:41 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	safe_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	cleanup_cmd_fds(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->fd_inf >= 0)
	{
		close(cmd->fd_inf);
		cmd->fd_inf = -1;
	}
	if (cmd->fd_out >= 0)
	{
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
}

void	cleanup_all_fds(t_cmd *cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		cleanup_cmd_fds(current);
		current = current->next;
	}
}

void	close_all_fds(t_controller *cont)
{
	cleanup_all_fds(cont->cmdlist.cmds);
}

void	cleanup_and_exit(t_controller *cont, int code)
{
	close_all_fds(cont);
	controller_free(cont);
	exit(code);
}
