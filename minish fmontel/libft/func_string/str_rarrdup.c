/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rarrdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:24 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 18:00:41 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Return a reverse duplicate an array of strings (char **)
 * as a new array of strings
 */
char	**str_rarrdup(char **strarr)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	if (!strarr)
		return (NULL);
	size = str_arrlen((const char **)strarr);
	s = malloc((size + 1) * sizeof(char *));
	while (i != size)
	{
		s[i] = str_dup(strarr[size - i]);
		i++;
	}
	s[size] = NULL;
	return (s);
}

/**
 * @brief Return a duplicate an array of strings (char **) as a new
 * array of strings and add 'str' at the start of it
 */
char	**str_rarrdup_nset(char **strarr, char *str)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	if (!strarr && !str)
		return (NULL);
	if (strarr && !str)
		return (str_arrdup(strarr));
	if (!strarr && str)
	{
		s = mem_calloc(2, sizeof(char *));
		s[0] = str_dup(str);
		return (s);
	}
	size = str_arrlen((const char **)strarr);
	s = mem_calloc((size + 2), sizeof(char *));
	s[0] = str_dup(str);
	while (i != size)
	{
		s[i + 1] = str_dup(strarr[i]);
		i++;
	}
	return (s);
}
