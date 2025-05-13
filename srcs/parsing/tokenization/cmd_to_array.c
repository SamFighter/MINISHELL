/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:21:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * Convert all the arguments tokens to a char ** for each commands
 */
void	cmd_to_array(t_cmdlist **cmdlist)
{
	t_cmd	*cmds;
	t_token	*tk;
	int		i;

	i = 0;
	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == PIPE && cmds->next)
		{
			cmds = cmds->next;
			tk = cmds->tokens;
			i = 0;
		}
		if (tk->type == ARG || tk->type == LIT_CHR || tk->type == LIT_STR)
			cmds->args = strarr_dupnset(cmds->args, (tk->string));
		tk = tk->next;
	}
	find_start_cmds(&cmds);
	(*cmdlist)->cmds = cmds;
	cmd_to_array_2(cmdlist);
}

/**
 * Convert non-arguments tokens for each commands:
 * - Command token to string 
 * - Input-files tokens to a char **
 * - Output-files tokens to a char **
 */
void	cmd_to_array_2(t_cmdlist **cmdlist)
{
	t_cmd	*cmds;
	t_token	*tk;

	cmds = (*cmdlist)->cmds;
	tk = cmds->tokens;
	while (tk)
	{
		if (tk->type == CMD)
			cmds->str_cmd = ft_strdup(tk->string);
		if (tk->type == INPUT)
			cmds->infiles = strarr_dupnset(cmds->infiles, tk->string);
		if (tk->type == OUTPUT)
			cmds->outfiles = strarr_dupnset(cmds->outfiles, tk->string);
		tk = tk->next;
	}
	find_start_cmds(&cmds);
	(*cmdlist)->cmds = cmds;
	cmd_to_array_3(cmdlist);
}

/**
 * @brief Find environment-variable name in argument
 * tokens and stock them in char **
 */
void	cmd_to_array_3(t_cmdlist **cmdlist)
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
		if (ft_strlchr(tk->string, '$') != -1)
			cmds->env_str = mult_strenv(cmds->env_str, tk->string);
		tk = tk->next;
	}
	find_start_cmds(&cmds);
	(*cmdlist)->cmds = cmds;
}
