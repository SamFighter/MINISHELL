/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:29:52 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 19:09:46 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * Join the strings (char *) 's1 and 's2' and return the joined string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
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
