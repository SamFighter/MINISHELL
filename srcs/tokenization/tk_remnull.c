/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_remnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:06:01 by fmontel           #+#    #+#             */
/*   Updated: 2025/06/30 16:06:01 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	tk_remnull2(t_token	**token);

void	tk_remnull(t_cmd **cmds)
{
	t_cmd	*cmd;

	if (!(*cmds) || !(*cmds)->tokens)
		return ;
	cmd = *cmds;
	cmd_tostart(&cmd);
	while (cmd)
	{
		tk_tostart(&cmd->tokens);
		if (cmd->tokens)
			tk_remnull2(&cmd->tokens);
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
}

void	tk_remnull2(t_token	**token)
{
	t_token	*tk;

	tk = *token;
	while (tk->next)
	{
		if (!tk->string && tk->type != INPUT && tk->type != OUTPUT)
			tk_fuse(&tk, &tk->next);
		if (tk->next)
			tk = tk->next;
		else
			break ;
	}
	if (!tk->string && tk->prev)
	{
		tk = tk->prev;
		tk_fuse(&tk, &tk->next);
	}
	*token = tk;
}
