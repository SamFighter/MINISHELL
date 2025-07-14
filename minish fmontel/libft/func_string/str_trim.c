/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:43:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:06:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Return a duplicate string (char *) 's1' without the 'set' string
 * at the start and end of the string
 */
char	*str_trim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	start = 0;
	end = str_len(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ctn_chckchar(s1[start], set))
		start++;
	while (ctn_chckchar(s1[end], set))
		end--;
	return (str_substr((char *)s1, start, end - start + 1));
}
