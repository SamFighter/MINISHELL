/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:12:09 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/10 17:41:45 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Print a string (char *) 'str' in the console, if str is NULL, print (null)
 */
void	utl_putstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		write(1, "(null)", 6);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * @brief Print a string (char *) 'str' in the console and
 * return the number of printed characters
 * 
 * if str is NULL, print (null) and return 6
 */
int	utl_putlstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * @brief Print a string (char *) 's' in the file-desciptior 'fd',
 * if str is NULL, print (null)
 */
void	utl_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		write(fd, "(null)", 6);
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/**
 * @brief Print a string (char *) 'str' in the console and
 * return the number of printed characters
 * 
 * if str is NULL, print (null) and return 6
 */
int	utl_putlstr_fd(const char *str, int fd)
{
	int		i;

	i = 0;
	if (!str)
	{
		i += write(fd, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
