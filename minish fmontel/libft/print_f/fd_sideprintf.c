/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sideprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:05 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/06 17:03:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	fd_printadd(void *ptr, int fd)
{
	unsigned long	add;
	int				len;

	add = (unsigned long) ptr;
	len = 0;
	if (ptr == NULL)
	{
		len += write(fd, "(nil)", 5);
		return (len);
	}
	len += write(fd, "0x", 2);
	len += fd_putnbr_hexa_low(add, fd);
	return (len);
}

int	fd_putnbr_hexa_low(unsigned long nb, int fd)
{
	int		len;
	char	hexc;

	len = 0;
	if (nb > 15)
		len += fd_putnbr_hexa_low(nb / 16, fd);
	hexc = "0123456789abcdef"[nb % 16];
	write(fd, &hexc, 1);
	len += 1;
	return (len);
}

int	fd_putnbr_hexa_up(unsigned long nb, int fd)
{
	int		len;
	char	hexc;

	len = 0;
	if (nb > 15)
		len += fd_putnbr_hexa_up(nb / 16, fd);
	hexc = "0123456789ABCDEF"[nb % 16];
	write(fd, &hexc, 1);
	len += 1;
	return (len);
}

int	fd_putnbr_unsigned(unsigned int nb, int fd)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += fd_putnbr_unsigned(nb / 10, fd);
	len += utl_putlchar_fd((nb % 10) + 48, fd);
	return (len);
}
