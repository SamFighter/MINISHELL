/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:24:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:25:50 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Set 'n' 'c'-valued bytes in the area pointed to by 's' 
 */
void	*mem_set(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
