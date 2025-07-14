/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:08:14 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/06 16:24:28 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Print 1 'c' character in the console
 */
void	utl_putchar(const char c)
{
	write(1, &c, 1);
}

/**
 * Print 1 'c' character in the console and return 1
 */
int	utl_putlchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * Print 1 'c' character in the file-desciptior 'fd'
 */
void	utl_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/**
 * Print 1 'c' character in the file-desciptior 'fd' qnd return 1
 */
int	utl_putlchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
