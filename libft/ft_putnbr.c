/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:18 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/28 15:53:56 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Print an int in the console
 */
void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		n = n % 10;
		ft_putchar(n + '0');
	}
}

/**
 * Print an int in the console, return the number of characters printed
 */
int	ft_putlnbr(int n)
{
	int		len;

	len = len_int(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		n = n % 10;
		ft_putchar(n + '0');
	}
	return (len);
}

void	recursive_print(int nb, int fd)
{
	int		i;
	char	c;

	if (nb > 0)
	{
		i = nb % 10;
		nb /= 10;
		c = i + 48;
		recursive_print(nb, fd);
		write(fd, &c, 1);
	}
}

/**
 * Print an int in the file-descriptor 'fd'
 */
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	recursive_print(nb, fd);
}
