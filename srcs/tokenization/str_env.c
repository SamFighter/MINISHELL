/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:24:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/15 16:06:39 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/headers/libft.h"

int	is_lit(char *str, int start);

/**
 * Return an environment-varible name as a string (char *), NULL if none
 */
char	*str_env(char *str, int start)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (!str || (size_t)start >= str_len(str)
		|| (!ctn_isalpha(str[start + 1]) && !(str[start + 1] == '_')
			&& !(str[start + 1] == '?') && !(str[start + 1] == '_')))
		return (s);
	start = ctn_strlnchr(str, '$', start);
	while (str[i + start] && (ctn_isalnum((int)str[i + start])
			|| str[i + start] == '?' || str[i + start] == '_'
			|| (i == 0 && str[i + start] == '$')))
		i++;
	if (i > 0 && !is_lit(str, start))
		s = str_substr(str, start, i);
	return (s);
}

/**
 * Return all environment-varible name as a string (char **), NULL if none
 */
char	**mult_str_env(char **env, char *str)
{
	int		start;
	char	*tmp;

	if (!str)
		return (NULL);
	start = -1;
	while (1)
	{
		start = ctn_strlnchr(str, '$', start + 1);
		if (start == -1)
			break ;
		tmp = str_env(str, start);
		env = str_arrrep_nset(env, tmp);
		free(tmp);
	}
	return (env);
}

int	is_lit(char *str, int start)
{
	int	i;
	int	pos[2];
	int	quotes;

	i = -1;
	pos[0] = -1;
	pos[1] = -1;
	quotes = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && quotes == 0)
			quotes = 1;
		else if (str[i] == '\"')
			quotes = 0;
		if (quotes == 0 && pos[0] == -1 && str[i] == '\'')
			pos[0] = i;
		else if (quotes == 0 && str[i] == '\'')
		{
			pos[1] = i;
			if (start > pos[0] && start < pos[1])
				return (1);
			return (0);
		}
	}
	return (0);
}
