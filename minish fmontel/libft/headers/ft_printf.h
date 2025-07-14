/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/08 09:20:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//\\=========================LIBRARY=========================//

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

//\\=======================FUNCTION=========================//

void	utl_printf(const	char *str, ...);
int		ft_printf(const	char *str, ...);
int		ft_putnbr_hexa_low(unsigned long nb);
int		ft_putnbr_hexa_up(unsigned long nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printadd(void *ptr);

int		fd_printf(int fd, const	char *str, ...);
int		fd_putnbr_hexa_low(unsigned long nb, int fd);
int		fd_putnbr_hexa_up(unsigned long nb, int fd);
int		fd_putnbr_unsigned(unsigned int nb, int fd);
int		fd_printadd(void *ptr, int fd);

#endif