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

#include "../../../headers/minishell.h"

/**
 * Call all the functions to tokenize the command line in the right order
 */
int	tokenizer(char *str, t_cmdlist *cmdlist)
{
	while (str && ft_iswhitespace(*str))
		str++;
	if (*str == 0)
		return (0);
	getlen_token(str, cmdlist);
	find_start_tokens(&cmdlist->tokens);
	create_tokens(str, cmdlist);
	set_type_token(cmdlist);
	find_start_cmds(&cmdlist->cmds);
	cmd_to_array(&cmdlist);
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
		lit = check_literals(str, i, lit);
		cmdlist->tokens->len++;
		if (lit == 0 && i > 0 && check_symbols(str, i) == 1)
		{
			cmdlist->tokens = init_nexttoken(cmdlist->tokens, str[i + 1]);
			cmdlist->tokens->len++;
		}
		if ((lit == 0 && ft_iswhitespace(str[i])
				&& cmdlist->tokens->len > 0))
		{
			while (str[i] && ft_iswhitespace(str[i]))
				++i;
			if (str[i] == 0)
				return (stop_end_token(cmdlist->tokens));
			cmdlist->tokens = init_nexttoken(cmdlist->tokens, str[--i + 1]);
		}
	}
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
		while (str[i] && ft_iswhitespace(str[i]))
			++i;
		tk->string = ft_substr(str, i, tk->len);
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
			token_pipe(&cmdlist->cmds, &tk);
		if (!set && token_infile(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && token_outfile(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && !cmdlist->cmds->has_cmd
			&& token_cmd(&cmdlist->cmds, &tk))
			set = 1;
		else if (!set && !check_symbols_token(tk->string))
			token_arg(&cmdlist->cmds, &tk);
		tk = tk->next;
		if (tk)
		{
			cmdlist->cmds->tokens = init_nexttoken(cmdlist->cmds->tokens, 1);
		}
	}
}
