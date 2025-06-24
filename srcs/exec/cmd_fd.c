/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:46:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/27 15:03:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int  get_fd(char *filename, int type)
{
    int fd;

    fd = -2;
    if (type == IN)
        fd = open(filename, O_RDONLY);
    else if (type == OUT)
        fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    else if (type == HEREDOC)
        fd = here_doc(filename);
    else if (type == APPEND)
        fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
    if (fd < 0)
        perror(filename);
    return (fd);
}

static int	handle_input_redirect(t_token *tok, t_cmd *cmd, int type)
{
	if (cmd->fd_inf >= 0)
		close(cmd->fd_inf);
	if (tok->next->string && tok->next == NULL)
		return (1);
	cmd->fd_inf = get_fd(tok->next->string, type);
	if (cmd->fd_inf < 0)
		return (1);
	return (0);
}

int	get_infile(t_token *tok, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = tok;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == IN || tmp->type == HEREDOC)
		{
			if (!tmp->next || !tmp->next->string)
				return (1);
			if (handle_input_redirect(tmp, cmd, tmp->type))
				return (1);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	handle_output_redirect(t_token *tok, t_cmd *cmd, int type)
{
	if (cmd->fd_out >= 0)
		close(cmd->fd_out);
	if (tok->next == NULL && !tok->next->string)
		return (1);
	cmd->fd_out = get_fd(tok->next->string, type);
	if (cmd->fd_out < 0)
		return (1);
	return (0);
}

int get_outfile(t_token *tok, t_cmd *cmd)
{
    t_token *tmp;

    tmp = tok;
    while (tmp && tmp->type != PIPE)
    {
        if (tmp->type == OUT || tmp->type == APPEND)
        {
            if (!tmp->next || !tmp->next->string || tmp->next->type == PIPE)
                return (1);
            if (handle_output_redirect(tmp, cmd, tmp->type))
                return (1);
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
    return (0);
}
