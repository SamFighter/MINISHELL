/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:24 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:59:15 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Duplicate an array of strings (char **) as a new array of strings
 */
char	**strarr_dup(char **strar)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	if (!strar)
		return (NULL);
	size = strarr_len((const char **)strar);
	s = malloc((size + 1) * sizeof(char *));
	while (i != size)
	{
		s[i] = ft_strdup(strar[i]);
		i++;
	}
	s[i] = NULL;
	return (s);
}

/**
 * @brief Duplicate an array of strings (char **) as a new array of strings
 * and add 'str' at the end of it
 */
char	**strarr_dupnset(char **strar, char *str)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	if (!strar && !str)
		return (NULL);
	if (!str)
		return (strarr_dup(strar));
	if (!strar)
	{
		s = malloc(2 * sizeof(char *));
		s[0] = ft_strdup(str);
		s[1] = NULL;
		return (s);
	}
	size = strarr_len((const char **)strar);
	s = malloc((size + 2) * sizeof(char *));
	while (i != size)
	{
		s[i] = ft_strdup(strar[i]);
		i++;
	}
	s[i] = ft_strdup(str);
	return (s);
}
