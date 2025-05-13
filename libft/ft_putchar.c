/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:08:14 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/28 15:51:58 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Print 1 'c' character in the console
 */
void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

/**
 * Print 1 'c' character in the console and return 1
 */
int	ft_putlchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * Print 1 'c' character in the file-desciptior 'fd'
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
