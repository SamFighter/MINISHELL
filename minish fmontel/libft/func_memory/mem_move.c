/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:24:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:41:20 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Move 'n' values from the area pointed to by 'src' to 'dest'
 */
void	*mem_move(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest >= src)
		while (n-- > 0)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
