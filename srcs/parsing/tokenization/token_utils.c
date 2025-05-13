/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:58:40 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:21:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * Find the start of a token linked-list
 */
void	find_start_tokens(t_token **tk)
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
 * @brief Find the start of a command linked-list and of
 * their respective token linked-lists
 */
void	find_start_cmds(t_cmd **cmd)
{
	t_token	*tk;

	while ((*cmd)->prev != NULL)
	{
		tk = (*cmd)->tokens;
		find_start_tokens(&tk);
		(*cmd)->tokens = tk;
		(*cmd) = (*cmd)->prev;
	}
	tk = (*cmd)->tokens;
	find_start_tokens(&tk);
	(*cmd)->tokens = tk;
}
