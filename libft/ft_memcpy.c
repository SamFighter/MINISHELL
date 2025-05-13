/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:24:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 15:27:09 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Copy 'n' values from the area pointed to by 'src' to 'dest'
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
