/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:18 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/12 13:38:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	recursive_print(int nb, int fd);

/**
 * Print an int in the console
 */
void	utl_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			utl_putchar('-');
		}
		if (n >= 10)
		{
			utl_putnbr(n / 10);
		}
		n = n % 10;
		utl_putchar(n + '0');
	}
}

/**
 * Print an int in the console, return the number of characters printed
 */
int	utl_putlnbr(int n)
{
	int		len;

	len = utl_int_len(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			utl_putchar('-');
		}
		if (n >= 10)
		{
			utl_putnbr(n / 10);
		}
		n = n % 10;
		utl_putchar(n + '0');
	}
	return (len);
}

/**
 * @brief Print an int in the file-descriptor 'fd', return the number
 * of characters printed
 */
int	utl_putlnbr_fd(int n, int fd)
{
	int		len;

	len = utl_int_len(n);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			utl_putchar_fd('-', fd);
		}
		if (n >= 10)
		{
			utl_putnbr_fd(n / 10, fd);
		}
		n = n % 10;
		utl_putchar_fd(n + '0', fd);
	}
	return (len);
}

/**
 * Print an int in the file-descriptor 'fd'
 */
void	utl_putnbr_fd(int nb, int fd)
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
