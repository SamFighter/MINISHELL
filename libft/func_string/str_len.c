/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:14:09 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 02:42:02 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Return the lenght of the string (char *) 's'
 */
size_t	str_len(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != 0)
		i++;
	return (i);
}

/**
 * Return the lenght of the double string array (char **) 's'
 */
size_t	str_arrlen(const char **s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != NULL)
		i++;
	return (i);
}
