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
 * Duplicate a token node and return it as a new token
 * - Doing so help prevent the token from beeing linked to the wrong list 
 */
t_token	*tk_dup(t_cmd **cmd, t_token *original_tk, int type)
{
	t_token	*new_tk;

	new_tk = tk_init();
	new_tk->prev = (*cmd)->tokens->prev;
	if (original_tk)
	{
		new_tk->string = str_dup(original_tk->string);
		new_tk->env_str = str_arrdup(original_tk->env_str);
		new_tk->len = original_tk->len;
	}
	new_tk->type = type;
	free((*cmd)->tokens);
	return (new_tk);
}

/**
 * Change the lenght of the string of the last token in the list,
 * Return 0
 */
void	tk_end(t_token *tk)
{
	tk->len--;
}
