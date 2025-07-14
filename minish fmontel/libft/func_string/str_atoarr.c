/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_atoarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:04:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/17 14:04:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Cut the string (char *) 'str' into an array of string (char **)
 * - Cut at each 'c' character
 */
char	**str_atoarr(char *str, char c)
{
	char	*tmp;
	char	**s;
	int		start;
	int		len;

	start = 0;
	s = NULL;
	while ((size_t)start < str_len(str))
	{
		len = utl_getlen_line(str, start, c);
		tmp = str_substr(str, start, len);
		s = str_arrdup_nset(s, tmp);
		if (tmp)
			free(tmp);
		start += len + 1;
	}
	return (s);
}

/**
 * Cut the string (char *) 'str' into an array of string (char **)
 * - Cut at each white-space character
 */
char	**str_atoarr_ws(char *str)
{
	char	*tmp;
	char	**s;
	int		start;
	int		len;

	start = 0;
	s = NULL;
	while ((size_t)start < str_len(str))
	{
		len = utl_getlen_line_ws(str, start);
		tmp = str_substr(str, start, len);
		s = str_arrrep_nset(s, tmp);
		if (tmp)
			free(tmp);
		start += len + 1;
	}
	return (s);
}
