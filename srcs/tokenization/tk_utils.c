/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:35:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/15 15:56:53 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
		new_tk->len = original_tk->len;
	}
	new_tk->type = type;
	free((*cmd)->tokens);
	return (new_tk);
}

/**
 * Fuse the next token into the current one
 */
void	tk_fuse(t_token **token, t_token **tk_next)
{
	t_token	*tk;
	t_token	*next;

	tk = *token;
	if (!token || !tk_next)
		return ;
	next = *tk_next;
	tk->string = str_rejoin(tk->string, next->string);
	if (next->string)
		free(next->string);
	next->string = NULL;
	tk->env_str = str_arrrejoin(tk->env_str, next->env_str);
	if (next->env_str)
		utl_super_free((void **)next->env_str);
	next->env_str = NULL;
	if (next->next)
	{
		next->next->prev = tk;
		tk->next = next->next;
		*tk_next = next->next;
	}
	else
		*tk_next = NULL;
	free(next);
	next = NULL;
}

/**
 * @brief Inject a linked-list in between the open and close link of a list and
 * return the close token without modifying were the open token point to;
 */
t_token	*tk_inject(t_token **open, t_token*close, t_token *inject)
{
	t_token	*tk;

	if (inject)
	{
		tk = *open;
		tk_tostart(&inject);
		tk->next = inject;
		inject->prev = tk;
		tk_tolast(&inject);
		inject->next = close;
		if (close)
			close->prev = inject;
		*open = tk;
		if (close)
			return (close);
		else
			return (inject);
	}
	else
		return (close);
}

/**
 * Add a node after the curent node of a token linked list and return new node
 */
t_token	*tk_addnode(t_token *tk, t_token **tk_all)
{
	t_token	*new;
	t_token	*all;

	all = *tk_all;
	if (tk && tk->next)
	{
		new = tk->next;
		tk->next = tk_initnext(tk, 0);
		tk->next = new;
		if (new)
			new->prev = tk;
	}
	else if (tk)
	{
		tk->next = tk_initnext(tk, 1);
		new = tk;
	}
	else
	{
		tk_tolast(&all);
		all->next = tk_init();
		all->next->prev = all;
		new = all->next;
	}
	return (new);
}
