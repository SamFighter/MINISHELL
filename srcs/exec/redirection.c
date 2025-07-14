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

static int	handle_input_redirection(t_cmd *cmd)
{
	if (cmd->fd_inf >= 0)
	{
		if (dup2(cmd->fd_inf, STDIN_FILENO) == -1)
		{
			perror("dup2 input");
			return (-1);
		}
		close(cmd->fd_inf);
		cmd->fd_inf = -1;
	}
	return (0);
}

static int	handle_output_redirection(t_cmd *cmd, int *pip)
{
	if (cmd->fd_out >= 0)
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2 output");
			return (-1);
		}
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
	else if (pip != NULL)
	{
		if (dup2(pip[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 pipe");
			return (-1);
		}
		close(pip[1]);
	}
	return (0);
}

int	redir_in_out(t_cmd *cmd, int *pip)
{
	if (handle_input_redirection(cmd) == -1)
		return (-1);
	if (handle_output_redirection(cmd, pip) == -1)
		return (-1);
	return (0);
}

int	len_cmd(t_cmd *cmd)
{
	int		count;
	t_cmd	*start;

	count = 0;
	start = cmd;
	if (!cmd)
		return (0);
	while (cmd && (count == 0 || cmd != start))
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}
