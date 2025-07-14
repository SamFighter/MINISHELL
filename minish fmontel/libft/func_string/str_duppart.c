/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_duppart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/06/19 15:58:54 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Duplicate part of a string and return it
 */
char	*str_duppart(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s || len <= 0)
		return (NULL);
	if ((size_t)len > str_len(s) - start)
		len = str_len(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
