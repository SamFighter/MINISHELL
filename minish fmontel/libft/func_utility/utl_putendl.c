/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_putendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:06:17 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:24:31 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Print a string (char *) 's' and a \\n after it in the console
 */
void	utl_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

/**
 * Print a string (char *) 's' and a \\n after it in the file-desciptior 'fd'
 */
void	utl_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
