/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 19:47:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_STR_H
# define FUNC_STR_H

# include "libft.h"

char		*str_dup(char *s);
int			*str_dup_int(char *s);
char		*str_dup_nset(char *s, char c);
char		**str_arrdup(char **strarr);
char		**str_arrdup_nset(char **strarr, char *str);
char		**str_rarrdup(char **strarr);
char		**str_rarrdup_nset(char **strarr, char *str);
char		**str_arrrep(char **strarr, char *str, int pos);
char		**str_arrrep_nset(char **strarr, char *str);
char		**str_split(char const *s, char c);
char		*str_join(char const *s1, char const *s2);
void		str_cat(char *dst, const char *src);
size_t		str_lcat(char *dst, const char *src);
size_t		str_lncat(char *dst, const char *src, size_t size);
void		str_cpy(char *dst, const char *src);
void		str_lcpy(char *dst, const char *src, size_t size);
size_t		str_lncpy(char *dst, const char *src, size_t size);
int			str_strcmp(char *s1, char *s2);
int			str_ncmp(const char *s1, const char *s2, size_t n);
char		*str_str(char *str, char *to_find);
char		*str_lstr(const char *big, const char *little, size_t len);
int			str_nstr(const char *big, const char *little);
int			str_lnstr(const char *big, const char *little, size_t start);
char		*str_trim(char const *s1, char const *set);
char		*str_substr(char *s, int start, int len);
char		*str_subrstr(char *s, int end, int len);
size_t		str_len(const char *s);
size_t		str_arrlen(const char **s);

void		str_iteri(char *s, void (*f)(unsigned int, char*));
char		*str_mapi(char const *s, char (*f)(unsigned int, char));

#endif