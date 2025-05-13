/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:43:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 17:31:21 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Duplicate a string (char *) 's1' without a scond 'set' string and return it
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (charchk(s1[start], set))
		start++;
	while (charchk(s1[end], set))
		end--;
	return (ft_substr((char *)s1, start, end - start + 1));
}
