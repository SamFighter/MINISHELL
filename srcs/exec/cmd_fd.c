/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:46:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 19:04:41 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	get_fd(char *filename, int type)
{
	int		fd;

	fd = -2;
	if (type == IN)
		fd = open(filename, O_RDONLY);
	else if (type == OUT)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (type == HEREDOC && g_sig != SIGINT)
		fd = here_doc(filename);
	else if (type == APPEND)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (type != HEREDOC && fd < 0)
		perror(filename);
	return (fd);
}

static int	handle_input_redirect(t_token *tok, t_cmd *cmd, int type)
{
	int	new_fd;

	if (!tok->next || !tok->next->string)
		return (1);
	new_fd = get_fd(tok->next->string, type);
	if (new_fd < 0)
	{
		if (type == HEREDOC && g_sig == SIGINT)
			return (130);
		return (1);
	}
	if (cmd->fd_inf >= 0)
		close(cmd->fd_inf);
	cmd->fd_inf = new_fd;
	return (0);
}

int	get_infile(t_token *tok, t_cmd *cmd)
{
	t_token	*tmp;
	int		res;

	tmp = tok;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == IN || tmp->type == HEREDOC)
		{
			if (!tmp->next || !tmp->next->string)
				return (1);
			res = handle_input_redirect(tmp, cmd, tmp->type);
			if (res != 0)
				return (res);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	handle_output_redirect(t_token *tok, t_cmd *cmd, int type)
{
	int	new_fd;

	if (cmd->fd_out >= 0)
		close(cmd->fd_out);
	if (!tok->next || !tok->next->string)
		return (1);
	new_fd = get_fd(tok->next->string, type);
	if (new_fd < 0)
		return (1);
	cmd->fd_out = new_fd;
	return (0);
}

int	get_outfile(t_token *tok, t_cmd *cmd)
{
	t_token	*tmp;
	int		result;

	tmp = tok;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == OUT || tmp->type == APPEND)
		{
			if (!tmp->next || !tmp->next->string || tmp->next->type == PIPE)
				return (1);
			result = handle_output_redirect(tmp, cmd, tmp->type);
			if (result != 0)
				return (result);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
