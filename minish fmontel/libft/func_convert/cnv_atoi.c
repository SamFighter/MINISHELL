/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:17:22 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:28:01 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
* Convert a string (char *) into an int untill it encounter an non-num character
* - Skip white space at the start of the string
* - Recognize one + or - character at the start of the string
*/
int	cnv_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
}

/*
* Convert a string (char *) into an int if possible, else return 0
* - Skip white space at the start of the string
* - Recognize one + or - character at the start of the string
*/
int	cnv_strict_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != 0)
		return (0);
	return (nb * neg);
}
