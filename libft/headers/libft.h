/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:28:16 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include "ft_printf.h"

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_iswhitespace(int c);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t count);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t len, size_t size);
int			**dbl_calloc_int(size_t len, size_t s_len);

int			ft_toupper(int c);
int			ft_tolower(int c);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, char c);
int			ft_strlchr(const char *s, int c);
int			ft_strlnchr(const char *s, int c, int start);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strstr(char *str, char *to_find);
int			ft_strcmp(char *s1, char *s2);

int			charchk(char c, char const *str);
int			charnchk(char c, char const *str);
size_t		ft_strlen(const char *s);
size_t		strarr_len(const char **s);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
int			sf_tablen(char **tab_str);
int			len_int(long int n);
int			strict_atoi(const char *nptr);

char		*ft_strdup(char *s);
char		*ft_strdupnset(char *s, char c);
int			*ft_strdup_int(char *s);
char		**strarr_dup(char **strar);
char		**strarr_dupnset(char **strar, char *str);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_substr(char *s, int start, int len);
char		*ft_subrstr(char *s, int end, int len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_conf(int const *s1, int len);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putchar(const char c);
int			ft_putlchar(const char c);
void		ft_putnbr(int n);
int			ft_putlnbr(int n);
void		ft_putstr(const char *str);
int			ft_putlstr(const char *str);

char		**super_free(void **str);
int			**super_free_int(int **id, int len);

//----------------------------------------------------------

char		*ctoa(char *str, char c, char *append);
char		*mult_ctoa(char *str, char c, char *append);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

#endif
