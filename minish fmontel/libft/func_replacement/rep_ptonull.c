/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_ptonull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 15:45:09 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief duplicate of the string (char *) 'str' without the
 * character at 'pos'
 * @warning - 'str' is NOT freed at the end
 */
char	*rep_ptonull(char *str, int pos)
{
	char	*s;
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	s = mem_calloc(str_len(str), sizeof(char));
	while (str[++i])
	{
		if (i == pos && j == 0)
			j = 1;
		if (j == 0)
			s[i] = str[i];
		else if (j == 1)
			s[i] = str[i + 1];
	}
	return (s);
}
