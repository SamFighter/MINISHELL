/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cnv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:23:01 by fmontel          ###   ########.fr       */
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

#endif