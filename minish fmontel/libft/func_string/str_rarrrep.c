/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rarrrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:24 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/04 10:34:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Return a reverse duplicate an array of strings (char **)
 * as a new array of strings
 */
char	**str_rarrrep(char **strarr)
{
	char	**s;

	s = str_rarrdup(strarr);
	utl_super_free((void **)strarr);
	return (s);
}

/**
 * @brief Return a duplicate an array of strings (char **) as a new
 * array of strings and add 'str' at the start of it
 */
char	**str_rarrrep_nset(char **strarr, char *str)
{
	char	**s;

	s = str_rarrdup_nset(strarr, str);
	utl_super_free((void **)strarr);
	return (s);
}
