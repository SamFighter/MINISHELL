/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:43:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/16 18:43:26 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * Initialize a new token node for a linked-list of and all it's content to null
 */
t_token	*tk_init(void)
{
	t_token	*new_tk;

	new_tk = malloc(sizeof(t_token));
	new_tk->next = NULL;
	new_tk->prev = NULL;
	new_tk->string = NULL;
	new_tk->env_str = NULL;
	new_tk->len = 0;
	new_tk->type = 0;
	return (new_tk);
}

/**
 * @brief Initialize a the next token node of a linked-list and set it's
 * previous value to the existing token
 */
t_token	*tk_initnext(t_token *tk, char c)
{
	if (c != 1)
		tk->len--;
	tk->next = tk_init();
	tk->next->prev = tk;
	return (tk->next);
}

/**
 * Change the lenght of the string of the last token in the list,
 * Return 0
 */
void	tk_end(t_token *tk)
{
	tk->len--;
}
