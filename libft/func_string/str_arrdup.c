/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:24 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:09:11 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Return a duplicate an array of strings (char **) as a new array of strings
 */
char	**str_arrdup(char **strarr)
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
		s[i] = str_dup(strarr[i]);
		i++;
	}
	s[i] = NULL;
	return (s);
}

/**
 * @brief Return a duplicate an array of strings (char **) as a new
 * array of strings and add 'str' at the end of it
 */
char	**str_arrdup_nset(char **strarr, char *str)
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
	while (i != size)
	{
		s[i] = str_dup(strarr[i]);
		i++;
	}
	s[i] = str_dup(str);
	return (s);
}

/**
 * @brief Return a duplicate an array of strings (char **)
 * as a new array of strings witout the string at position 'rem'
 */
char	**str_arrdup_nrem(char **strarr, int rem)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	if (!strarr)
		return (NULL);
	size = str_arrlen((const char **)strarr) - 1;
	if (size <= 0)
		return (NULL);
	s = malloc((size + 1) * sizeof(char *));
	if (i < 0)
		i = 0;
	while (i != size)
	{
		if (i < rem)
			s[i] = str_dup(strarr[i]);
		else
			s[i] = str_dup(strarr[size + 1]);
		i++;
	}
	s[size] = NULL;
	return (s);
}
