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

/**
 * Convert all the arguments tokens to a char ** for each commands
 */
void	cmd_toarr(t_cmdlist **cmdlist, char **env)
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
		if (tk->type == CMD)
			cmds->str_cmd = str_dup(tk->string);
		tk = tk->next;
	}
	cmd_tostart(&cmds);
	(*cmdlist)->cmds = cmds;
	cmd_toarr2(cmdlist, env);
}

/**
 * @brief Find environment-variable name in argument
 * tokens and stock them in char **
 */
void	cmd_toarr2(t_cmdlist **cmdlist, char **env)
{
	t_cmd	*cmds;
	t_token	*tk;
	int		lits;

	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		lits = ctn_strlchr(tk->string, '$');
		if (tk->type == PIPE && cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
		}
		if (lits != -1 && ((lits == 0 && tk->string[0] != '\'' && tk->string)
				|| (tk->string[lits - 1] != '\'' && tk->string)))
			tk->env_str = mult_str_env(tk->env_str, tk->string);
		tk = tk->next;
	}
	cmd_tostart(&cmds);
	expander(cmds, env);
	(*cmdlist)->cmds = cmds;
	cmd_toarr3(cmdlist);
}

/**
 * Convert non-arguments tokens for each commands:
 * - Command token to string 
 * - Input-files tokens to a char **
 * - Output-files tokens to a char **
 */
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
		else if (cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
		}
		else
			break ;
	}
	cmd_tostart(&cmds);
	(*cmdlist)->cmds = cmds;
}
