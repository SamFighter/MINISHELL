/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_getlen_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:06:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/17 14:06:46 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Return the lenght of the line from 'start' to the first 'c'
 * in the string (char *) 's'
 */
int	utl_getlen_line(char *s, int start, char c)
{
	size_t	i;

	i = start;
	if (s == NULL)
		return (i);
	while (s[i] && s[i] != c)
		i++;
	return (i - start);
}

/**
 * @brief Return the lenght of the line from 'start' to the first white-spqce
 * in the string (char *) 's'
 */
int	utl_getlen_line_ws(char *s, int start)
{
	size_t	i;

	i = start;
	if (s == NULL)
		return (i);
	while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\r')
		&& s[i] != '\n' && s[i] != '\v' && s[i] != '\f')
		i++;
	return (i - start);
}
