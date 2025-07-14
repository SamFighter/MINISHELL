/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cnv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:04:28 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_CNV_H
# define FUNC_CNV_H

int			cnv_atoi(const char *nptr);
int			cnv_strict_atoi(const char *nptr);
char		*cnv_itoa(int n);
size_t		cnv_atost(const char *nptr);
size_t		cnv_strict_atost(const char *nptr);
char		*cnv_sttoa(size_t n);
char		*cnv_str(const	char *str, ...);

char		*additional_adrs(void *ptr);
char		*additional_hexa_low(unsigned long nb);
char		*additional_hexa_up(unsigned long nb);
char		*additional_unbr(unsigned int nb);

#endif