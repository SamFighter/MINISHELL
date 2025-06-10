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

static int  in_and_heredoc(t_token *tok, t_cmd *cmd)
{
    if (tok->type == IN)
    {
        if (cmd->fd_inf >= 0)
            close(cmd->fd_inf);
		if (tok->next == NULL)
			return (1);
        cmd->fd_inf = get_fd(tok->next->string, IN);
        if (cmd->fd_inf < 0)
            return (1);
    }
    else if (tok->type == HEREDOC)
	{
		if (cmd->fd_inf >= 0)
			close(cmd->fd_inf);
		if (tok == tok->next)
			return (1);
		if (tok->next == NULL)
			return (1);
		cmd->fd_inf = get_fd(tok->next->string, HEREDOC);
		if (cmd->fd_inf == -1)
			return (1);
	}
	return (0);
}

int get_infile(t_token *tok, t_cmd *cmd)
{
    t_token *tmp;

    tmp = tok;
    if (in_and_heredoc(tmp, cmd))
        return (1);
    if (tmp->type == PIPE)
        return (0);
    tmp = tmp->next;
    while (tmp && tmp->type != PIPE)
    {
        if (in_and_heredoc(tmp, cmd))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

static int out_and_append(t_token *tok, t_cmd *cmd)
{
    if (tok->type == OUT)
    {
        if (cmd->fd_out >= 0)
            close(cmd->fd_out);
	  	if (tok->next == NULL)
			return (1);
        cmd->fd_out = get_fd(tok->next->string, OUT);
        if (cmd->fd_out < 0)
            return (1);
    }
    else if (tok->type == APPEND)
    {
        if (cmd->fd_out >= 0)
            close(cmd->fd_out);
		if (tok->next == NULL)
			return (1);
        cmd->fd_out = get_fd(tok->next->string, APPEND);
        if (cmd->fd_out < 0)
            return (1);
    }
    return (0);
}

int get_outfile(t_token *tok, t_cmd *cmd)
{
    t_token *tmp;

    tmp = tok;
    if (out_and_append(tmp, cmd))
        return (1);
    tmp = tmp->next;
    while (tmp && tmp->type != PIPE)
    {
        if (out_and_append(tmp, cmd))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
