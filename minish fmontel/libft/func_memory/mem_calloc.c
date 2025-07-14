/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:39:19 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 19:38:46 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Malloc an array of type 'size' and of lenght 'len' and is set to 0
 *
 * - Example:
 * char* str = mem_calloc(5 * sizeof(char));
 */
void	*mem_calloc(size_t len, size_t size)
{
	unsigned char	*s;

	if (len <= 0 || size <= 0)
		return (NULL);
	s = malloc(len * size);
	if (!s)
		return (NULL);
	mem_bzero(s, len * size);
	return (s);
}

/**
 * Malloc a double array of int:
 *  
 * The main array is of lenght 'len',
 * the secondary ones are of lenght 's_len' and are set to 0 with ft_bzero
 *
 * - Example:
 * int** i = mem_calloc_dbl_i(5, 3);
 */
int	**mem_dbl_calloc_int(size_t len, size_t s_len)
{
	int		**s;
	size_t	i;

	i = 0;
	if (len <= 0)
		return (NULL);
	s = malloc(len * sizeof(int *));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = malloc(s_len * sizeof(int));
		if (!s[i])
			return (NULL);
		mem_bzero(s[i], s_len * sizeof(int));
		i++;
	}
	return (s);
}
