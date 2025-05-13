/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:07:41 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/17 14:07:41 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * Initialize a new command node for a linked-list and all it's content to null,
 * The token node of a new linked-list of the new command node is initialized
 */
t_cmd	*init_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	new_cmd->nb_tokens = 0;
	new_cmd->has_cmd = 0;
	new_cmd->args = NULL;
	new_cmd->outfiles = NULL;
	new_cmd->infiles = NULL;
	new_cmd->str_cmd = NULL;
	new_cmd->tokens = tk_init();
	return (new_cmd);
}
