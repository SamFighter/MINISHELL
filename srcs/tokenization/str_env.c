/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:24:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:56:30 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/headers/libft.h"

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
		|| (!ctn_isalpha(str[start + 1]) && !(str[start + 1] == '_')))
		return (s);
	start = ctn_strlnchr(str, '$', start);
	while (str[i + start] && (ctn_isalnum((int)str[i + start])
			|| str[i + start] == '_' || (i == 0 && str[i + start] == '$')))
		i++;
	if (i > 0)
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
	char	**new_env;

	if (!str)
		return (NULL);
	start = -1;
	while (1)
	{
		start = ctn_strlnchr(str, '$', start + 1);
		if (start == -1)
			break ;
		tmp = str_env(str, start);
		new_env = str_rarrdup_nset(env, tmp);
		utl_super_free((void **)env);
		env = str_arrdup(new_env);
		free(tmp);
		utl_super_free((void **)new_env);
	}
	return (env);
}
