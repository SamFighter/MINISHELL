/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:14:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 17:55:03 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Compare the characters in the strings (char *) 's1' and 's2',
 * return the difference.
 */
int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/**
 * Compare 'n' number of characters in the strings (char *) 's1' and 's2',
 * return the difference.
 */
int	str_ncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		else if (c1[i] == 0 && c2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
