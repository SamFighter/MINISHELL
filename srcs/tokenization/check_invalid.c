/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:40:28 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/17 09:49:31 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	check_invalid2(t_cmd	*cmd);

int	check_invalid(t_cmd	**cmds)
{
	t_cmd	*cmd;
	char	*s;

	if (!(*cmds) || !(*cmds)->tokens || !(*cmds)->tokens->string)
		return (99);
	cmd = *cmds;
	cmd_tostart(&cmd);
	while (cmd)
	{
		s = cmd->tokens->string;
		if (cmd->tokens->type == HEREDOC && str_len(s) == 3)
			return (3);
		if (cmd->tokens->type == HEREDOC && str_len(s) > 3)
			return (4);
		if (check_invalid2(cmd))
			return (check_invalid2(cmd));
		if (cmd->tokens->next)
			cmd->tokens = cmd->tokens->next;
		else if (!cmd->tokens->next && cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	return (0);
}

int	check_invalid2(t_cmd	*cmd)
{
	char	*s;

	s = cmd->tokens->string;
	if (!s && (cmd->tokens->type == INPUT || cmd->tokens->type == OUTPUT))
		return (9);
	if (!s)
		return (0);
	if (cmd->tokens->type == APPEND && str_len(s) == 3)
		return (5);
	if (cmd->tokens->type == APPEND && str_len(s) > 3)
		return (6);
	if (s[0] == '|' && (cmd->tokens->prev == NULL
			|| cmd->tokens->type == 5 || cmd->tokens->type == 6
			|| !cmd->next))
		return (7);
	if (s[0] == '<' && (cmd->tokens->type == 5 || cmd->tokens->type == 6))
		return (3);
	if (s[0] == '>' && (cmd->tokens->type == 5 || cmd->tokens->type == 6))
		return (5);
	if (cmd->tokens->type < 0 && !cmd->tokens->next)
		return (8);
	if (!cmd->tokens->next && cmd->next)
		cmd = cmd->next;
	return (0);
}
