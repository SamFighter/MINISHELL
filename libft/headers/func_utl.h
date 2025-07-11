/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:05:36 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_UTL_H
# define FUNC_UTL_H

# include "libft.h"

void		utl_putchar(const char c);
int			utl_putlchar(const char c);
void		utl_putchar_fd(char c, int fd);
int			utl_putlchar_fd(char c, int fd);
void		utl_putstr(const char *str);
int			utl_putlstr(const char *str);
void		utl_putstr_fd(char *str, int fd);
int			utl_putlstr_fd(const char *str, int fd);
void		utl_putendl(char *s);
void		utl_putendl_fd(char *s, int fd);
void		utl_putnbr(int n);
int			utl_putlnbr(int n);
void		utl_putnbr_fd(int nb, int fd);
int			utl_putlnbr_fd(int n, int fd);
char		**utl_super_free(void **str);
int			**utl_super_free_int(int **id, int len);
int			utl_int_len(long int n);
int			utl_dbl_arrlen(char **tab_str);
void		utl_putarrstr(const char **strarr);
int			utl_putlarrstr(const char **strarr);
void		utl_putarrstr_fd(char **strarr, int fd);
int			utl_putlarrstr_fd(char **strarr, int fd);
int			utl_getlen_line(char *s, int start, char c);
int			utl_getlen_line_ws(char *s, int start);

#endif