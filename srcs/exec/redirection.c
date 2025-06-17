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

void	redir_in_out(t_controller *cont, t_cmd *cmd, int *pip)
{
	(void)cont;
	if (cmd->fd_inf > 2)
	{
		dup2(cmd->fd_inf, STDIN_FILENO);
		close(cmd->fd_inf);
	}
	if (cmd->fd_out > 2)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	else if (pip != NULL)
	{
		dup2(pip[1], STDOUT_FILENO);
	}
	if (pip != NULL)
	{
		close(pip[0]);
		close(pip[1]);
	}
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
