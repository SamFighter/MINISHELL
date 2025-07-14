/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:29:13 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:41:19 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Set 'c' characters in the area pointed to by 's' for 'n' characters
 */
void	*mem_chr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	ch;
	size_t			i;

	dest = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (i != n)
	{
		if (dest[i] == ch)
			return (dest + i);
		i++;
	}
	return (NULL);
}
