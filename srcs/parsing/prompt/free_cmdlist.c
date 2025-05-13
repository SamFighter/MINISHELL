/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:43:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/16 18:43:26 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * Free the values of the cmdlist
 */
void	free_cmdlist(t_cmdlist *cmdlist)
{
	find_start_tokens(&cmdlist->tokens);
	free_tokens(cmdlist->tokens);
	cmdlist->tokens = NULL;
	free_cmd(cmdlist->cmds);
	cmdlist->cmds = NULL;
}

/**
 * Free the tokens linked-list and all the existng nodes
 */
void	free_tokens(t_token *tk)
{
	while (tk)
	{
		if (tk->prev)
			free(tk->prev);
		free(tk->string);
		tk->type = 0;
		tk->len = 0;
		if (tk->next)
			tk = tk->next;
		else
		{
			free(tk);
			return ;
		}
	}
}

/**
 * Free the command linked-list and all the existng nodes
 */
void	free_cmd(t_cmd	*cmd)
{
	while (cmd)
	{
		if (cmd->prev)
			free(cmd->prev);
		if (cmd->args)
			super_free((void **)cmd->args);
		if (cmd->outfiles)
			super_free((void **)cmd->outfiles);
		if (cmd->infiles)
			super_free((void **)cmd->infiles);
		if (cmd->str_cmd)
			free(cmd->str_cmd);
		if (cmd->env_str)
			free(cmd->env_str);
		cmd->nb_tokens = 0;
		cmd->has_cmd = 0;
		free_tokens(cmd->tokens);
		if (cmd->next)
			cmd = cmd->next;
		else
		{
			free(cmd);
			return ;
		}
	}
}
