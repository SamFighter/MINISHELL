/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 18:23:59 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * @brief Replace one character 'c' in a duplicate of the string (char *)
 * 'str' by the string 'append'
 */
char	*ctoa(char *str, char c, char *append)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	o;

	i = -1;
	o = 0;
	s = ft_calloc((ft_strlen(str) + ft_strlen(append)), sizeof(char));
	while (str[++i])
	{
		j = 0;
		if (o == 0 && str[i] != c)
			s[i] = str[i];
		else if (o == 1)
			s[i - 1 + ft_strlen(append)] = str[i];
		while (str[i] == c && o == 0 && append[j])
		{
			s[i + j] = append[j];
			j++;
		}
		if (!append[j])
			o++;
	}
	return (s);
}

/**
 * @brief Replace every character 'c' in a duplicate of the string (char *)
 * 'str' by the string 'append'
 */
char	*mult_ctoa(char *str, char c, char *append)
{
	int		i;
	int		nb;
	char	*s;
	char	*tmp;

	i = 0;
	nb = charnchk(c, str);
	s = ft_strdup(str);
	while (i < nb)
	{
		tmp = ctoa(s, c, append);
		free(s);
		s = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (s);
}
