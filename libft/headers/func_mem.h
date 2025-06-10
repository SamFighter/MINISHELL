/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:41:36 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_MEM_H
# define FUNC_MEM_H

# include "libft.h"

void		mem_bzero(void *s, size_t n);
void		*mem_calloc(size_t len, size_t size);
int			**mem_dbl_calloc_int(size_t len, size_t s_len);
int			mem_cmp(const void *s1, const void *s2, size_t n);
void		*mem_set(void *s, int c, size_t n);
void		*mem_cpy(void *dest, const void *src, size_t n);
void		*mem_move(void *dest, const void *src, size_t count);
void		*mem_chr(const void *s, int c, size_t n);

#endif
