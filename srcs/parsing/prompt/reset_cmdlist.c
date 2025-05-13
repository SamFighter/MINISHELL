/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cmdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:57:28 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:18:30 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * Reset the values of the cmdlist to null and re-initialize the cmd and token
 */
void	reset_cmdlist(t_cmdlist *cmdlist)
{
	find_start_tokens(&cmdlist->tokens);
	free_tokens(cmdlist->tokens);
	cmdlist->tokens = init_token();
	free_cmd(cmdlist->cmds);
	cmdlist->cmds = init_cmd();
}
