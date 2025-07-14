/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arrrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:24 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:36:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Replace an array of strings (char **) with a copy of 'strarr'
 * and replace the string (char *) at the position 'pos' with 'str'
 * 
 * - If 'pos' is supperior to the size of the array of string it will
 * replace the last string
 * @warning - 'strarr' is freed at the end
 */
char	**str_arrrep(char **strarr, char *str, int pos)
{
	int		arrlen;
	char	**s;

	s = NULL;
	if (!strarr)
		return (s);
	if (!str)
	{
		s = str_arrdup(strarr);
		free(strarr);
	}
	else
	{
		arrlen = str_arrlen((const char **)strarr);
		if (pos >= arrlen)
			pos = arrlen - 1;
		s = str_arrdup(strarr);
		free(s[pos]);
		s[pos] = str_dup(str);
	}
	utl_super_free((void **)strarr);
	return (s);
}

/**
 * @brief Replace an array of strings (char **) with a copy of 'strarr'
 * and add 'str' at the end of it
 * @warning - 'strarr' is freed at the end
 */
char	**str_arrrep_nset(char **strarr, char *str)
{
	char	**s;

	s = str_arrdup_nset(strarr, str);
	utl_super_free((void **)strarr);
	return (s);
}

/**
 * @brief Replace an array of strings (char **) with a copy of 'strarr'
 * and remove the string at position 'rem'
 * @warning - 'strarr' is freed at the end
 */
char	**str_arrrep_nrem(char **strarr, int rem)
{
	char	**s;

	s = str_arrdup_nrem(strarr, rem);
	utl_super_free((void **)strarr);
	return (s);
}
