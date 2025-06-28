/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_sttoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:02:22 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 08:42:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	tochar(char *s, size_t nb, size_t len);
size_t	getlen(size_t n);

/**
 * Convert a size_t into a string (char *)
 */
char	*cnv_sttoa(size_t n)
{
	size_t	len;
	char	*s;

	if (n == 4294967295)
		return ("4294967295");
	len = getlen(n) + 1;
	if (n == 0)
		len++;
	s = malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	tochar(s, n, len);
	return (s);
}

void	tochar(char *s, size_t nb, size_t len)
{
	size_t		i;

	i = 0;
	if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[len - i - 2] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	s[len - 1] = 0;
}

size_t	getlen(size_t n)
{
	size_t		len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
