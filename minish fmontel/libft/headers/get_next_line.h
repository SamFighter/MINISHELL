/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:15:12 by fmontel           #+#    #+#             */
/*   Updated: 2024/11/04 12:15:14 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*dump_line(int fd, char *dump, char *buffer);
char	*clean_dump(char *dest);

#endif
