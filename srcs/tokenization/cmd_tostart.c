/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tostart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:58:40 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:31:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Find the start of a command linked-list and of
 * their respective token linked-lists
 */
void	cmd_tostart(t_cmd **cmd)
{
	t_token	*tk;

	while ((*cmd) && (*cmd)->next)
		(*cmd) = (*cmd)->next;
	while ((*cmd)->prev)
	{
		tk = (*cmd)->tokens;
		tk_tostart(&tk);
		(*cmd)->tokens = tk;
		(*cmd) = (*cmd)->prev;
	}
	tk = (*cmd)->tokens;
	tk_tostart(&tk);
	(*cmd)->tokens = tk;
}

/**
 * Find the start of a token linked-list
 */
void	tk_tostart(t_token **tk)
{
	t_token	*new_tk;

	new_tk = *tk;
	while (new_tk->prev != NULL)
	{
		new_tk->prev->next = new_tk;
		new_tk = new_tk->prev;
	}
	*tk = new_tk;
}

/**
 * Find the last token of a token linked-list
 */
void	tk_tolast(t_token **tk)
{
	t_token	*new_tk;

	new_tk = *tk;
	while (new_tk->next)
		new_tk = new_tk->next;
	*tk = new_tk;
}
