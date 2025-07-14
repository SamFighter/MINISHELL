/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:17:30 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/04 10:31:16 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*get_info_2(char c, va_list arg)
{
	char	*s;

	if (c == 'd' || c == 'i')
		s = cnv_itoa(va_arg(arg, int));
	else
	{
		s = str_addc(NULL, '%');
		s = str_addc(NULL, c);
	}
	return (s);
}

char	*get_info(char c, va_list arg)
{
	char	*s;

	if (c == 'u')
		s = additional_unbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		s = additional_hexa_low(va_arg(arg, unsigned int));
	else if (c == 'X')
		s = additional_hexa_up(va_arg(arg, unsigned int));
	else if (c == '%')
		s = str_addc(NULL, '%');
	else if (c == 'c')
		s = str_addc(NULL, va_arg(arg, int));
	else if (c == 's')
		s = str_dup(va_arg(arg, char *));
	else if (c == 'p')
		s = additional_adrs(va_arg(arg, void *));
	else
		s = get_info_2(c, arg);
	return (s);
}

/**
 * @brief Replace the inputed string in the console and support
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
 * - S: string array (char **) DEACTIVATED FOR NOW
 * 
 * - p: pointer adress
 * 
 * - x: hexadecimal (lower-case)
 * 
 * - X: hexadecimal (upper-case)
 */
char	*cnv_str(const	char *str, ...)
{
	va_list		arg;
	int			i;
	char		*s;
	char		*tmp;

	va_start(arg, str);
	s = NULL;
	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (str[i] != '%')
			s = str_addc(s, str[i]);
		else
		{
			tmp = get_info(str[++i], arg);
			s = str_rejoin(s, tmp);
			free(tmp);
		}
	}
	return (s);
}
