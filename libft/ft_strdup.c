/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 17:23:05 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Duplicate a string and return it
 */
char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*src;

	i = 0;
	len = ft_strlen(s);
	src = malloc((len + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i] != '\0')
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

/**
 * @brief Duplicate a string and add a character 'c'
 * at the end of the duplicate string before returning it
 */
char	*ft_strdupnset(char *s, char c)
{
	size_t		i;
	size_t		len;
	char		*src;

	i = 0;
	len = ft_strlen(s);
	src = malloc((len + 2) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i] != '\0')
	{
		src[i] = s[i];
		i++;
	}
	src[i] = c;
	src[i + 1] = '\0';
	return (src);
}

/**
 * Duplicate a array of int and return it
 */
int	*ft_strdup_int(char *s)
{
	int		i;
	int		len;
	int		*src;

	i = 0;
	len = ft_strlen(s);
	src = malloc((len + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i] != '\0')
	{
		src[i] = (int)s[i];
		i++;
	}
	return (src);
}
