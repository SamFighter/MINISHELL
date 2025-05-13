/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_lit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:56:43 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 18:09:25 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*rem_lit_tk(char *tk, int type);
char	*rem_lit(char *str, int start, int end);

/**
 * Remove quote from every cmds->tokens->string as needed
 */
void	rem_litstr(t_cmd *cmds)
{
	while (cmds)
	{
		while (cmds->tokens)
		{
			if (cmds->tokens->string[0] == '\"')
				cmds->tokens->string = rem_lit_tk(cmds->tokens->string, 1);
			if (cmds->tokens->string[0] == '\'')
				cmds->tokens->string = rem_lit_tk(cmds->tokens->string, 2);
			else
				cmds->tokens->string = rem_lit_tk(cmds->tokens->string, 0);
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

char	*rem_lit_tk(char *s, int type)
{
	int		i;
	int		pos[2];

	i = -1;
	pos[1] = -1;
	while ((size_t)++i < str_len(s))
	{
		if (type == 0 || (type != 0 && i == 0))
			pos[0] = i;
		else if (type == 0 && s[i] == '\"')
			type = 1;
		else if (type == 0 && s[i] == '\'')
			type = 2;
		else if ((type == 1 && s[i] == '\"') || (type == 2 && s[i] == '\''))
			pos[1] = i;
		if (pos[1] != -1)
		{
			s = rem_lit(s, pos[0], pos[1]);
			type = 0;
			pos[1] = -1;
			i -= 2;
		}
	}
	return (s);
}

char	*rem_lit(char *str, int start, int end)
{
	char	*s;
	char	*tmp;

	tmp = rep_ptonull(str, end);
	s = rep_ptonull(tmp, start);
	free(str);
	free(tmp);
	return (s);
}
