/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:52 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/15 22:16:08 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Join the strings (char *) 's1 and 's2' and return the joined string
 */
char	*str_join(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		i;
	int		j;

	len = str_len(s1) + str_len(s2);
	s = malloc(len * sizeof(char) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	return (s);
}

/**
 * @brief Join the strings (char *) 's1 and 's2' and return the
 * joined string and free 's1'
 */
char	*str_rejoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1)
		return (str_dup(s2));
	if (!s2)
		return (s1);
	s = mem_calloc(str_len(s1) + str_len(s2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		s[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s);
}
