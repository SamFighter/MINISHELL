/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_atost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:17:22 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:27:53 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
* @brief Convert a string (char *) into a size_t untill it encounter an non-num
* character
* 
* - Skip white space at the start of the string
*/
size_t	cnv_atost(const char *nptr)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb);
}

/*
* Convert a string (char *) into a size_t if possible, else return 0
* - Skip white space at the start of the string
*/
size_t	cnv_strict_atost(const char *nptr)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != 0)
		return (0);
	return (nb);
}
