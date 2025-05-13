/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:14:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:41:19 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Compare 'n' values from the area pointed to by 's1' and 's2',
 * return the difference.
 * 
 * - Example:
 *  ft_memcmp("abcd", "abcz") -> 22
 */
int	mem_cmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			i;

	d1 = (unsigned char *) s1;
	d2 = (unsigned char *) s2;
	i = 0;
	while (i != n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
