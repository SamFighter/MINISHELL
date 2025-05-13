/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:37:04 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Copy as nuch characters from the 'src' string (char *)
 * into the 'dst' string
 */
void	str_cpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!str_len(src))
		return ;
	while (dst[i] && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

/**
 * @brief Copy 'size' number of character from the 'src' string (char *)
 * into the 'dst' string
 * @warning Copying more characters than the 'dst' can contain
 * will result in an error
 */
void	str_lcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return ;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

/**
 * @brief Copy 'size' number of character from the 'src' string (char *)
 * into the 'dst' string and return the lenght of the 'src' string
 * @warning Copying more characters than the 'dst' can contain
 * will result in an error
 */
size_t	str_lncpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = str_len(src);
	i = 0;
	if (size <= 0)
		return (j);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
