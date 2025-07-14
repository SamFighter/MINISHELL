/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_toarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 17:18:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	cmd_toarr2(t_cmdlist **cmdlist, char **env, int excode);
void	cmd_toarr3(t_cmdlist **cmdlist);
void	cmd_toarr4(t_cmdlist **cmdlist);

/**
 * Convert all the arguments tokens to a char ** for each commands
 */
void	cmd_toarr(t_cmdlist **cmdlist, char **env, int excode)
{
	t_cmd	*cmds;
	t_token	*tk;

	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == PIPE && cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
		}
		tk = tk->next;
	}
	cmd_tostart(&cmds);
	(*cmdlist)->cmds = cmds;
	cmd_toarr2(cmdlist, env, excode);
}

void	cmd_toarr2(t_cmdlist **cmdlist, char **env, int excode)
{
	t_cmd	*cmds;
	t_token	*tk;

	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == PIPE && cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
		}
		tk->env_str = mult_str_env(tk->env_str, tk->string);
		tk = tk->next;
	}
	cmd_tostart(&cmds);
	expander(cmds, env, excode);
	cmd_tostart(&cmds);
	rem_quote_str(cmds);
	(*cmdlist)->cmds = cmds;
	tk_remnull(&(*cmdlist)->cmds);
	cmd_tostart(&cmds);
	cmd_toarr3(cmdlist);
}

void	cmd_toarr3(t_cmdlist **cmdlist)
{
	t_cmd	*cmds;
	t_token	*tk;

	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == INPUT)
			cmds->infiles = str_arrrep_nset(cmds->infiles, tk->string);
		if (tk->type == OUTPUT)
			cmds->outfiles = str_arrrep_nset(cmds->outfiles, tk->string);
		if (tk->type >= ARG && tk->type <= LIT_CHR)
			cmds->args = str_arrrep_nset(cmds->args, (tk->string));
		if (tk->next)
			tk = tk->next;
		else if (!tk->next && cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
		}
		else
			break ;
	}
	(*cmdlist)->cmds = cmds;
	cmd_toarr4(cmdlist);
}

void	cmd_toarr4(t_cmdlist **cmdlist)
{
	t_cmd	*cmds;
	t_token	*tk;

	cmds = (*cmdlist)->cmds;
	cmd_tostart(&cmds);
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == CMD)
			cmds->str_cmd = str_rep(cmds->str_cmd, tk->string);
		tk = tk->next;
		if (cmds->next)
		{
			cmds = cmds->next;
			tk_tostart(&cmds->tokens);
			tk = cmds->tokens;
		}
		else
			break ;
	}
	cmd_tostart(&cmds);
	(*cmdlist)->cmds = cmds;
}
