/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ctn.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 04:00:59 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_CTN_H
# define FUNC_CTN_H

int			ctn_isalpha(int c);
int			ctn_isupper(int c);
int			ctn_islower(int c);
int			ctn_isdigit(int c);
int			ctn_isalnum(int c);
int			ctn_isascii(int c);
int			ctn_isprint(int c);
int			ctn_iswhitespace(int c);
int			ctn_ischar(char check, char target);
int			ctn_chckchar(char c, char const *str);
int			ctn_chcknchar(char c, char const *str);
char		*ctn_strchr(const char *s, int c);
int			ctn_strlchr(const char *s, int c);
int			ctn_strlnchr(const char *s, int c, int start);
char		*ctn_strrchr(const char *s, char c);
int			ctn_strrlchr(const char *s, int c);
int			ctn_strrlnchr(const char *s, int c, int end);

#endif