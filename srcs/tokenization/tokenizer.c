/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/16 19:04:56 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/debug.h"

/**
 * Call all the functions to tokenize the command line in the right order
 */
int	tokenizer(char *str, t_controller *cont)
{
	t_cmdlist	*cmdlist;

	g_sig = 0;
	while (str && ctn_iswhitespace(*str))
		str++;
	if (*str == 0)
		return (0);
	cmdlist = &cont->cmdlist;
	getlen_token(str, cmdlist);
	tk_tostart(&cmdlist->tokens);
	create_tokens(str, cmdlist);
	set_type_token(cmdlist);
	cmd_tostart(&cmdlist->cmds);
	cmd_toarr(&cmdlist, cont->env);
	rem_litstr(cmdlist->cmds);
	cmd_tostart(&cmdlist->cmds);
	// log_controller(cont, 1);
	// log_cmds(cont->cmdlist.cmds, 1);
	// log_tokens(cont->cmdlist.tokens, 1);
	return (1);
}

/**
 * Read the command line and generate new tokens in which to save their lenght
 */
void	getlen_token(char *str, t_cmdlist *cmdlist)
{
	int	lit;
	int	i;

	lit = 0;
	i = -1;
	while (str[++i])
	{
		lit = ctn_lit(str, i, lit);
		cmdlist->tokens->len++;
		if (lit == 0 && i > 0 && ctn_smbl(str, i) == 1)
		{
			cmdlist->tokens = tk_initnext(cmdlist->tokens, str[i + 1]);
			cmdlist->tokens->len++;
		}
		if ((lit == 0 && ctn_iswhitespace(str[i])
				&& cmdlist->tokens->len > 0))
		{
			while (str[i] && ctn_iswhitespace(str[i]))
				++i;
			if (str[i] == 0)
				return (tk_end(cmdlist->tokens));
			cmdlist->tokens = tk_initnext(cmdlist->tokens, str[--i + 1]);
		}
	}
	cmdlist->invalid = lit;
}

/**
 * Cut and save the tokens from their previously saved lenght
 */
void	create_tokens(char *str, t_cmdlist *cmdlist)
{
	int		i;
	t_token	*tk;

	i = 0;
	tk = cmdlist->tokens;
	while (tk && str[i])
	{
		while (str[i] && ctn_iswhitespace(str[i]))
			++i;
		tk->string = str_substr(str, i, tk->len);
		i += tk->len;
		tk = tk->next;
	}
}

/**
 * Copy the tokens in a command linked list and set their types
 */
void	set_type_token(t_cmdlist *cmdlist)
{
	t_token	*tk;
	int		set;

	tk = cmdlist->tokens;
	while (tk)
	{
		set = 0;
		if (tk && tk->string[0] == '|' && tk->string[1] != '|')
			tk_type_pipe(&cmdlist->cmds, &tk);
		if (!set && tk_type_infile(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && tk_type_outfile(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && !cmdlist->cmds->has_cmd
			&& tk_type_cmd(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && !ctn_smbl_tk(tk->string))
			tk_type_arg(&cmdlist->cmds, &tk);
		tk = tk->next;
		if (tk)
		{
			cmdlist->cmds->tokens = tk_initnext(cmdlist->cmds->tokens, 1);
		}
	}
}
