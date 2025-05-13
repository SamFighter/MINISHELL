/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_set_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:25:36 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:21:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * Return 1 if the token is an IN or HEREDOC, else return 0
 * - If true, it will try to set the next token as an INFILE (else NULL)
 */
int	token_infile(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '<')
	{
		if (tk->string[1] == 0)
			(*cmds)->tokens = dup_token(cmds, tk, IN);
		else if (tk->string[1] == '<')
			(*cmds)->tokens = dup_token(cmds, tk, HEREDOC);
		tk = tk->next;
		if (!tk)
			return (1);
		if (check_symbols_token(tk->string))
		{
			(*cmds)->tokens = dup_token(cmds, NULL, INPUT);
			return (1);
		}
		(*cmds)->tokens = dup_token(cmds, tk, INPUT);
		*token = tk;
	}
	else
		return (0);
	return (1);
}

/**
 * Return 1 if the token is an OUT or APPEND, else return 0
 * - If true, it will try to set the next token as an OUTFILE (else NULL)
 */
int	token_outfile(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '>')
	{
		if (tk->string[1] == 0)
			(*cmds)->tokens = dup_token(cmds, tk, OUT);
		else if (tk->string[1] == '>')
			(*cmds)->tokens = dup_token(cmds, tk, APPEND);
		tk = tk->next;
		if (!tk)
			return (1);
		if (check_symbols_token(tk->string))
		{
			(*cmds)->tokens = dup_token(cmds, NULL, OUTPUT);
			return (1);
		}
		(*cmds)->tokens = dup_token(cmds, tk, OUTPUT);
		*token = tk;
	}
	else
		return (0);
	return (1);
}

/**
 * Set the token as a CMD and return 1
 */
int	token_cmd(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	(*cmds)->has_cmd = 1;
	(*cmds)->tokens = dup_token(cmds, tk, CMD);
	*token = tk;
	return (1);
}

/**
 * Set the token as a PIPE and return 1
 * - If there are tokens left, initialize a new cmd node and change token
 */
void	token_pipe(t_cmd **cmds, t_token **token)
{
	t_token	*tk;
	t_cmd	*new_cmd;

	tk = *token;
	(*cmds)->tokens = dup_token(cmds, tk, PIPE);
	if (tk->next)
	{
		tk = tk->next;
		*token = tk;
		new_cmd = *cmds;
		new_cmd->next = init_cmd();
		new_cmd->next->prev = new_cmd;
		*cmds = new_cmd->next;
	}
}

/**
 * Set the token as an ARG, LITS or LITC depending on if the token is a literal
 */
void	token_arg(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '"')
	{
		(*cmds)->tokens = dup_token(cmds, tk, LIT_STR);
	}
	else if (tk->string[0] == '\'')
	{
		(*cmds)->tokens = dup_token(cmds, tk, LIT_CHR);
	}
	else
	{
		(*cmds)->tokens = dup_token(cmds, tk, ARG);
	}
	(*cmds)->nb_tokens++;
	*token = tk;
}
