/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:43:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 17:21:04 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * Reset the values of the cmdlist to null and re-initialize the cmd and token
 */
void	cmdlist_reset(t_cmdlist *cmdlist)
{
	tk_tostart(&cmdlist->tokens);
	tk_free(cmdlist->tokens);
	cmdlist->tokens = tk_init();
	cmd_free(cmdlist->cmds);
	cmdlist->cmds = init_cmd();
}

/**
 * Free the values of the cmdlist
 */
void	cmdlist_free(t_cmdlist *cmdlist)
{
	tk_tostart(&cmdlist->tokens);
	tk_free(cmdlist->tokens);
	cmdlist->tokens = NULL;
	cmd_free(cmdlist->cmds);
	cmdlist->cmds = NULL;
}

/**
 * Free the tokens linked-list and all the existng nodes
 */
void	tk_free(t_token *tk)
{
	while (tk)
	{
		if (tk->prev)
			free(tk->prev);
		if (tk->string)
			free(tk->string);
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
void	cmd_free(t_cmd	*cmd)
{
	while (cmd)
	{
		if (cmd->prev)
			free(cmd->prev);
		if (cmd->args)
			utl_super_free((void **)cmd->args);
		if (cmd->outfiles)
			utl_super_free((void **)cmd->outfiles);
		if (cmd->infiles)
			utl_super_free((void **)cmd->infiles);
		if (cmd->str_cmd)
			free(cmd->str_cmd);
		cmd->nb_tokens = 0;
		cmd->has_cmd = 0;
		tk_free(cmd->tokens);
		if (cmd->next)
			cmd = cmd->next;
		else
		{
			free(cmd);
			return ;
		}
	}
}
