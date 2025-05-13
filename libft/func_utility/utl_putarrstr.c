/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_putarrstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:12:09 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/10 17:40:07 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Print all strings (char *) from an array of string (char **)
 * 'strarr' in the console, if str is NULL, print (null)
 */
void	utl_putarrstr(const char **strarr)
{
	int		i;

	i = 0;
	if (!strarr)
		write(1, "(null)", 6);
	while (strarr[i])
	{
		utl_putstr(strarr[i]);
		utl_putchar('\n');
		i++;
	}
}

/**
 * @brief Print all strings (char *) from an array of string (char **)
 * 'strarr in the console and return the number of printed characters
 * 
 * if str is NULL, print (null) and return 6
 */
int	utl_putlarrstr(const char **strarr)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!strarr)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (strarr[i])
	{
		utl_putlstr(strarr[i]);
		utl_putchar('\n');
		i++;
		len += str_len(strarr[i]) + 1;
	}
	return (len);
}

/**
 * @brief Print all strings (char *) from an array of string (char **)
 * 'strarr' in the file-desciptior 'fd', if str is NULL, print (null)
 */
void	utl_putarrstr_fd(char **strarr, int fd)
{
	int	i;

	i = 0;
	if (!strarr)
		write(1, "(null)", 6);
	while (strarr[i])
	{
		utl_putstr_fd(strarr[i], fd);
		utl_putchar_fd('\n', fd);
		i++;
	}
}

/**
 * @brief Print all strings (char *) from an array of string (char **)
 * 'strarr in the file-desciptior and return the number of printed characters
 * 
 * if str is NULL, print (null) and return 6
 */
int	utl_putlarrstr_fd(char **strarr, int fd)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!strarr)
	{
		len += write(fd, "(null)", 6);
		return (len);
	}
	while (strarr[i])
	{
		utl_putlstr_fd(strarr[i], fd);
		utl_putchar_fd('\n', fd);
		i++;
		len += str_len(strarr[i]) + 1;
	}
	return (len);
}
