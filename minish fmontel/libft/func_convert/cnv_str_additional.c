/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_str_additional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:17:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/19 13:29:37 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*additional_adrs(void *ptr)
{
	char			*s;
	char			*tmp;

	if (ptr == NULL)
	{
		s = str_dup("(nil)");
		return (s);
	}
	s = str_dup("0x");
	tmp = additional_hexa_low((unsigned long) ptr);
	str_cat(s, tmp);
	free(tmp);
	return (s);
}

char	*additional_hexa_low(unsigned long nb)
{
	char	*hexc;

	hexc = NULL;
	if (nb > 15)
		hexc = additional_hexa_low(nb / 16);
	hexc = str_addc(hexc, "0123456789abcdef"[nb % 16]);
	return (hexc);
}

char	*additional_hexa_up(unsigned long nb)
{
	char	*hexc;

	hexc = NULL;
	if (nb > 15)
		hexc = additional_hexa_low(nb / 16);
	hexc = str_addc(hexc, "0123456789ABCDEF"[nb % 16]);
	return (hexc);
}

char	*additional_unbr(unsigned int nb)
{
	char	*s;

	s = NULL;
	if (nb > 9)
		s = additional_unbr(nb / 10);
	s = str_addc(s, (nb % 10) + 48);
	return (s);
}
