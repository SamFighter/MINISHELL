/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_ctonull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 15:29:16 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief duplicate of the string (char *) 'str' without the
 * first character 'c'
 * @warning - 'str' is NOT freed at the end
 */
char	*rep_ctonull(char *str, char c)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	s = mem_calloc(str_len(str), sizeof(char));
	while (str[++i])
	{
		if (str[i] == c && j == 0)
			j = 1;
		if (j == 0)
			s[i] = str[i];
		else if (j == 1)
			s[i] = str[i + 1];
	}
	return (s);
}

/**
 * @brief Replace every character 'c' in a duplicate of the string (char *)
 * 'str' by the string 'apn'
 * @warning - 'str' is freed at the end
 */
char	*rep_mult_ctonull(char *str, char c)
{
	int		i;
	int		nb;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	nb = ctn_chcknchar(c, str);
	if (nb == 0)
		return (str);
	while (i < nb)
	{
		s = rep_ctonull(str, c);
		free(str);
		str = str_dup(s);
		free(s);
		i++;
	}
	return (str);
}
