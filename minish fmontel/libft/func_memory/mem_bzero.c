/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:24:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:25:39 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Set 'n' zero-valued bytes in the area pointed to by 's' 
 */
void	mem_bzero(void *str, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
