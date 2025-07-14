/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:49 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 14:05:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/libft.h"

void	get_info(char c, va_list arg)
{
	if (c == 'u')
		ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		ft_putnbr_hexa_low(va_arg(arg, unsigned int));
	else if (c == 'X')
		ft_putnbr_hexa_up(va_arg(arg, unsigned int));
	else if (c == '%')
		utl_putchar('%');
	else if (c == 'c')
		utl_putchar(va_arg(arg, int));
	else if (c == 's')
		utl_putstr(va_arg(arg, char *));
	else if (c == 'S')
		utl_putarrstr(va_arg(arg, const char **));
	else if (c == 'p')
		ft_printadd(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		utl_putnbr(va_arg(arg, int));
	else
	{
		utl_putchar ('%');
		utl_putchar(c);
	}
}

/**
 * @brief Print the inputed string in the console and returns nothing,
 * it support some format specifiers:
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
 */
void	utl_printf(const	char *str, ...)
{
	va_list		arg;
	int			i;

	va_start(arg, str);
	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] != '%')
			utl_putchar(str[i]);
		else
		{
			get_info(str[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
}
