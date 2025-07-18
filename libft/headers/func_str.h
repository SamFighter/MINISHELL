/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/15 15:27:46 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_STR_H
# define FUNC_STR_H

# include "libft.h"

char		*str_dup(char *s);
int			*str_dup_int(char *s);
char		*str_dup_nset(char *s, char c);
char		*str_duppart(char *s, int start, int len);
char		**str_arrdup(char **strarr);
char		**str_arrdup_nset(char **strarr, char *str);
char		**str_rarrdup(char **strarr);
char		**str_rarrdup_nset(char **strarr, char *str);
char		**str_arrrep(char **strarr, char *str, int pos);
char		**str_arrrep_nset(char **strarr, char *str);
char		**str_rarrrep(char **strarr);
char		**str_rarrrep_nset(char **strarr, char *str);
char		**str_arrdup_nrem(char **strarr, int rem);
char		**str_split(char const *s, char c);
char		*str_join(char const *s1, char const *s2);
char		*str_rejoin(char *s1, char *s2);
char		*str_addc(char *str, char c);
void		str_cat(char *dst, const char *src);
size_t		str_lcat(char *dst, const char *src);
size_t		str_lncat(char *dst, const char *src, size_t size);
void		str_cpy(char *dst, const char *src);
void		str_lcpy(char *dst, const char *src, size_t size);
size_t		str_lncpy(char *dst, const char *src, size_t size);
int			str_cmp(char *s1, char *s2);
int			str_ncmp(const char *s1, const char *s2, size_t n);
char		*str_str(char *str, char *to_find);
char		*str_lstr(const char *big, const char *little, size_t len);
int			str_nstr(const char *big, const char *little);
int			str_lnstr(const char *big, const char *little, size_t start);
int			str_llstr(char *big, char *little, size_t len, int start);
int			str_nlstr(char *big, char *little, int start);
char		*str_trim(char const *s1, char const *set);
char		*str_substr(char *s, int start, int len);
char		*str_subrstr(char *s, int end, int len);
size_t		str_len(const char *s);
size_t		str_arrlen(const char **s);
char		**str_atoarr(char *str, char c);
char		**str_atoarr_ws(char *str);
char		*str_rep(char *s1, char *s2);
char		**sarr_add_if_none(char **sarr, char *s);
char		**str_arrjoin(char **arr1, char **arr2);
char		**str_arrrejoin(char **arr1, char **arr2);

void		str_iteri(char *s, void (*f)(unsigned int, char*));
char		*str_mapi(char const *s, char (*f)(unsigned int, char));

#endif
