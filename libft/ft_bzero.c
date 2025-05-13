/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:24:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 15:19:11 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Set 'n' zero-valued bytes in the area pointed to by 's' 
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
