/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_type_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:25:36 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 17:27:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * Return 1 if the token is an IN or HEREDOC, else return 0
 * - If true, it will try to set the next token as an INFILE (else NULL)
 */
int	tk_type_infile(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '<')
	{
		if (tk->string[1] == 0)
			(*cmds)->tokens = tk_dup(cmds, tk, IN);
		else if (tk->string[1] == '<')
			(*cmds)->tokens = tk_dup(cmds, tk, HEREDOC);
		tk = tk->next;
		(*cmds)->tokens = tk_initnext((*cmds)->tokens, 1);
		if (!tk)
			return (1);
		if (ctn_smbl_tk(tk->string))
		{
			(*cmds)->tokens = tk_dup(cmds, NULL, INPUT);
			return (1);
		}
		else
			(*cmds)->tokens = tk_dup(cmds, tk, INPUT);
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
int	tk_type_outfile(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '>')
	{
		if (tk->string[1] == 0)
			(*cmds)->tokens = tk_dup(cmds, tk, OUT);
		else if (tk->string[1] == '>')
			(*cmds)->tokens = tk_dup(cmds, tk, APPEND);
		tk = tk->next;
		(*cmds)->tokens = tk_initnext((*cmds)->tokens, 1);
		if (!tk)
			return (1);
		if (ctn_smbl_tk(tk->string))
		{
			(*cmds)->tokens = tk_dup(cmds, NULL, OUTPUT);
			return (1);
		}
		else
			(*cmds)->tokens = tk_dup(cmds, tk, OUTPUT);
		*token = tk;
	}
	else
		return (0);
	return (1);
}

/**
 * Set the token as a CMD and return 1
 */
int	tk_type_cmd(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	(*cmds)->has_cmd = 1;
	(*cmds)->tokens = tk_dup(cmds, tk, CMD);
	*token = tk;
	return (1);
}

/**
 * Set the token as a PIPE and return 1
 * - If there are tokens left, initialize a new cmd node and change token
 */
void	tk_type_pipe(t_cmd **cmds, t_token **token)
{
	t_token	*tk;
	t_cmd	*new_cmd;

	tk = *token;
	(*cmds)->tokens = tk_dup(cmds, tk, PIPE);
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
void	tk_type_arg(t_cmd **cmds, t_token **token)
{
	t_token	*tk;

	tk = *token;
	if (tk->string[0] == '"')
	{
		(*cmds)->tokens = tk_dup(cmds, tk, LIT_STR);
	}
	else if (tk->string[0] == '\'')
	{
		(*cmds)->tokens = tk_dup(cmds, tk, LIT_CHR);
	}
	else
	{
		(*cmds)->tokens = tk_dup(cmds, tk, ARG);
	}
	(*cmds)->nb_tokens++;
	*token = tk;
}
