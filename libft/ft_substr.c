/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:59:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 17:37:03 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Duplicate part of a string and return it:
 * - Duplicate from the position 'start' and for 'len' characters
 */
char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*src;

	i = 0;
	if ((size_t)(len + start) > ft_strlen(s))
		return (s);
	src = malloc((len + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i + start] != '\0' && i != len)
	{
		src[i] = s[i + start];
		i++;
	}
	src[i] = '\0';
	return (src);
}

/**
 * Duplicate part of a string and return it:
 * - Duplicate backward from the position 'end' and for 'len' characters
 */
char	*ft_subrstr(char *s, int end, int len)
{
	int		i;
	char	*src;

	i = 0;
	if ((size_t)len > ft_strlen(s))
		return (s);
	src = malloc((len + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i] != '\0' && i != len)
	{
		src[i] = s[end - i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
