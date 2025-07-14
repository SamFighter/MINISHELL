/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:15 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:06:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include <stdio.h>

static int	count_words(char const *src, char sep);
static char	**cut_words(char **dest, char const *s, char c);

/**
 * @brief Split a string (char *) into a double string (char **)
 * by cutting at characters 'c' and removing them in the string 's'
 */
char	**str_split(char const *s, char c)
{
	char	**dest;
	int		nbw;

	if (!s)
		return (NULL);
	nbw = count_words(s, c);
	if (!ctn_chckchar(c, s))
		nbw = 1;
	dest = malloc((nbw + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = cut_words(dest, s, c);
	return (dest);
}

static int	count_words(char const *src, char sep)
{
	int		is_c;
	int		nbw;

	is_c = 0;
	nbw = 0;
	while (*src)
	{
		if (*src != sep && is_c == 0)
		{
			is_c = 1;
			nbw++;
		}
		else if (*src == sep)
			is_c = 0;
		src++;
	}
	return (nbw);
}

static char	**cut_words(char **dest, char const *s, char c)
{
	size_t	o;
	size_t	end;
	int		start;

	o = 0;
	end = 0;
	start = -1;
	while (end <= str_len(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == str_len(s)) && start >= 0)
		{
			dest[o] = str_substr((char *)s, start, end - start);
			if (!dest[o])
				return (utl_super_free((void **)dest));
			start = -1;
			o++;
		}
		end++;
	}
	dest[o] = 0;
	return (dest);
}
