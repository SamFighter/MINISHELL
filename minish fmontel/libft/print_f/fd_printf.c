/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:49 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/12 13:47:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/libft.h"

static int	fd_get_info(char c, int len, va_list arg, int fd)
{
	if (c == 'u')
		len += fd_putnbr_unsigned(va_arg(arg, unsigned int), fd);
	else if (c == 'x')
		len += fd_putnbr_hexa_low(va_arg(arg, unsigned int), fd);
	else if (c == 'X')
		len += fd_putnbr_hexa_up(va_arg(arg, unsigned int), fd);
	else if (c == '%')
		len += utl_putlchar_fd('%', fd);
	else if (c == 'c')
		len += utl_putlchar_fd(va_arg(arg, int), fd);
	else if (c == 's')
		len += utl_putlstr_fd(va_arg(arg, char *), fd);
	else if (c == 'S')
		len += utl_putlarrstr_fd(va_arg(arg, char **), fd);
	else if (c == 'p')
		len += fd_printadd(va_arg(arg, void *), fd);
	else if (c == 'd' || c == 'i')
		len += utl_putlnbr_fd(va_arg(arg, int), fd);
	else
	{
		len += utl_putlchar_fd ('%', fd);
		len += utl_putlchar_fd(c, fd);
	}
	return (len);
}

/**
 * @brief Print the inputed string in the file-descriptor 'fd' and support
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
int	fd_printf(int fd, const	char *str, ...)
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
			len += utl_putlchar_fd(str[i], fd);
		else
		{
			len = fd_get_info(str[i + 1], len, arg, fd);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
