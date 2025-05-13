/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/28 16:00:06 by fmontel          ###   ########.fr       */
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

int		ft_putnbr_hexa_low(unsigned long nb);
int		ft_putnbr_hexa_up(unsigned long nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printf(const	char *str, ...);
int		ft_printadd(void *ptr);

#endif