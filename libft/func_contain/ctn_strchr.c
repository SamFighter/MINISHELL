/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:09:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Search for a character 'c' in the string (char *) 's' and
 * return the adress of the character in the string, return NULL if none
 */
char	*ctn_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == 0 && c == 0)
		return ((char *)s + i);
	return (NULL);
}

/**
 * @brief Search for a character 'c' in the string (char *) 's'
 * and return the position of the character in the string, return -1 if none
 */
int	ctn_strlchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == 0 && c == 0)
		return (i);
	return (-1);
}

/**
 * @brief Search for a character 'c' in the string (char *) 's' from 'start'
 * and return the position of the character in the string, return -1 if none
 */
int	ctn_strlnchr(const char *s, int c, int start)
{
	int	i;

	i = start;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == 0 && c == 0)
		return (i);
	return (-1);
}
