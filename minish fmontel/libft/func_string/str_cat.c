/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 07:33:20 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:58:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Add the 'src' string (char *) at the end of the 'dst' string
 */
void	str_cat(char *dst, const char *src)
{
	size_t	d_len;
	size_t	i;

	d_len = str_len((const char *)dst);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
}

/**
 * @brief Add the 'src' string (char *) at the end of the 'dst' string
 * and return the lenght of the joined string
 */
size_t	str_lcat(char *dst, const char *src)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = str_len((const char *)dst);
	s_len = str_len(src);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/**
 * @brief Add 'size' number of character from the the 'src' string (char *)
 * at the end of the 'dst' string and return the lenght of the joined string
 */
size_t	str_lncat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = str_len((const char *)dst);
	s_len = str_len(src);
	i = 0;
	if (size <= d_len)
		return (s_len + size);
	while (src[i] && i < size - d_len - i - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
