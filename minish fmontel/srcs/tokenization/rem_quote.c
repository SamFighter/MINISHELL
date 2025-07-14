/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:56:43 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:32:27 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*rem_quote_tk(char *tk, int type);
char	*rem_quote(char *str, int start, int end);
int		set_type(char c);

/**
 * Remove quote from every cmds->tokens->string as needed
 */
void	rem_quote_str(t_cmd *cmds)
{
	while (cmds)
	{
		while (cmds->tokens && cmds->tokens->string)
		{
			cmds->tokens->string = rem_quote_tk(cmds->tokens->string, 0);
			if (cmds->tokens->string[0] == 0)
			{
				free(cmds->tokens->string);
				cmds->tokens->string = NULL;
			}
			if (cmds->tokens->type == CMD)
			{
				free(cmds->str_cmd);
				cmds->str_cmd = str_dup(cmds->tokens->string);
			}
			if (!cmds->tokens->next)
				break ;
			cmds->tokens = cmds->tokens->next;
		}
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
}

char	*rem_quote_tk(char *s, int type)
{
	size_t	i;
	int		pos[2];

	i = -1;
	pos[0] = -1;
	pos[1] = -1;
	while ((size_t)++i < str_len(s))
	{
		if (pos[0] == -1 && (s[i] == '\"' || s[i] == '\''))
		{
			pos[0] = i;
			type = set_type(s[i]);
		}
		else if ((type == 1 && s[i] == '\"') || (type == 2 && s[i] == '\''))
			pos[1] = i;
		if (pos[1] != -1)
		{
			s = rem_quote(s, pos[0], pos[1]);
			type = 0;
			pos[0] = -1;
			pos[1] = -1;
			i -= 2;
		}
	}
	return (s);
}

char	*rem_quote(char *str, int start, int end)
{
	char	*s;
	char	*tmp;

	tmp = rep_ptonull(str, end);
	s = rep_ptonull(tmp, start);
	free(str);
	free(tmp);
	return (s);
}

int	set_type(char c)
{
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (2);
	return (0);
}
