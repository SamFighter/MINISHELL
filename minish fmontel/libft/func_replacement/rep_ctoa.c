/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_ctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 14:47:36 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Replace one character 'c' in a duplicate of the string (char *)
 * 'str' by the string 'append'
 * @warning - 'str' is NOT freed at the end
 */
char	*rep_ctoa(char *str, char c, char *apn)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	o;

	i = -1;
	o = 0;
	j = 0;
	s = mem_calloc((str_len(str) + str_len(apn)), sizeof(char));
	while (str[++i])
	{
		if (o == 0 && str[i] != c)
			s[i] = str[i];
		else if (o == 1)
			s[i - 1 + str_len(apn)] = str[i];
		while (str[i] == c && o == 0 && apn[j])
		{
			s[i + j] = apn[j];
			j++;
		}
		o = ctn_ischar(apn[j], 0);
	}
	return (s);
}

/**
 * @brief Replace every character 'c' in a duplicate of the string (char *)
 * 'str' by the string 'apn'
 * @warning - 'str' is freed at the end
 */
char	*rep_mult_ctoa(char *str, char c, char *apn)
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
		s = rep_ctoa(str, c, apn);
		free(str);
		str = str_dup(s);
		free(s);
		i++;
	}
	return (str);
}
