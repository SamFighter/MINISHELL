/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:15:00 by fmontel           #+#    #+#             */
/*   Updated: 2024/11/04 12:15:05 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/get_next_line.h"
#include "headers/libft.h"

/**
 * Return the next line of a file-descriptor 'fd' and return it
 */
char	*get_next_line(int fd)
{
	static char	*dump;
	char		*dest;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(dump);
		dump = NULL;
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	dest = dump_line(fd, (char *) dump, buffer);
	if (buffer)
		free(buffer);
	if (!dest)
	{
		free(dump);
		dump = NULL;
		return (NULL);
	}
	dump = clean_dump(dest);
	return (dest);
}

char	*dump_line(int fd, char *dump, char *buffer)
{
	long	readed;
	char	*tmp;

	readed = 0;
	while (readed >= 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		buffer[readed] = 0;
		if (readed == 0)
			return (dump);
		if (!dump)
			dump = str_dup("");
		tmp = dump;
		dump = str_join(tmp, buffer);
		free(tmp);
		if (ctn_strchr(buffer, '\n'))
			return (dump);
	}
	return (dump);
}

char	*clean_dump(char *dest)
{
	char	*dump;
	long	i;

	i = 0;
	if (dest[0] == 0)
	{
		dest = NULL;
		return (NULL);
	}
	while (dest[i] != '\n' && dest[i] != 0)
		i++;
	dump = str_substr(dest, i + 1, str_len(dest) - i);
	if (!dump || dump[0] == 0)
	{
		free(dump);
		return (NULL);
	}
	if (dest[i] != 0)
		dest[i + 1] = 0;
	return (dump);
}
