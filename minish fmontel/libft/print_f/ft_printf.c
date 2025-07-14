/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:49 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/12 13:47:28 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/libft.h"

static int	get_info(char c, int len, va_list arg)
{
	if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_hexa_low(va_arg(arg, unsigned int));
	else if (c == 'X')
		len += ft_putnbr_hexa_up(va_arg(arg, unsigned int));
	else if (c == '%')
		len += utl_putlchar('%');
	else if (c == 'c')
		len += utl_putlchar(va_arg(arg, int));
	else if (c == 's')
		len += utl_putlstr(va_arg(arg, char *));
	else if (c == 'S')
		len += utl_putlarrstr(va_arg(arg, const char **));
	else if (c == 'p')
		len += ft_printadd(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len += utl_putlnbr(va_arg(arg, int));
	else
	{
		len += utl_putlchar ('%');
		len += utl_putlchar(c);
	}
	return (len);
}

/**
 * @brief Print the inputed string in the console and support
 * some format specifiers:
 * 
 * - i: signed int
 * 
 * - d: signed int
 * 
 * - u: unsigned int
 * 
 * - c: character
 * 
 * - s: string (char *)
 * 
 * - S: string array (char **)
 * 
 * - p: pointer adress
 * 
 * - x: hexadecimal (lower-case)
 * 
 * - X: hexadecimal (upper-case)
 * @return Lenght of printed message
 */
int	ft_printf(const	char *str, ...)
{
	va_list		arg;
	int			i;
	int			len;

	va_start(arg, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			len += utl_putlchar(str[i]);
		else
		{
			len = get_info(str[i + 1], len, arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
