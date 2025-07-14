/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_ctoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 14:00:16 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Replace one character 'c' in a duplicate of the string (char *)
 * 'str' by the int 'apn'
 * @warning - 'str' is NOT freed at the end
 */
char	*rep_ctoi(char *str, char c, int apn)
{
	char	*s;
	char	*itoa;
	size_t	i;
	size_t	j;
	size_t	o;

	i = -1;
	o = 0;
	j = 0;
	itoa = cnv_itoa(apn);
	s = mem_calloc((str_len(str) + str_len(itoa)), sizeof(char));
	while (str[++i])
	{
		if (o == 0 && str[i] != c)
			s[i] = str[i];
		else if (o == 1)
			s[i - 1 + str_len(itoa)] = str[i];
		while (str[i] == c && o == 0 && itoa[j])
		{
			s[i + j] = itoa[j];
			j++;
		}
		o = ctn_ischar(itoa[j], 0);
	}
	return (s);
}

/**
 * @brief Replace every character 'c' in a duplicate of the string (char *)
 * 'str' by the int 'apn'
 * @warning - 'str' is NOT freed at the end
 */
char	*rep_mult_ctoi(char *str, char c, int apn)
{
	int		i;
	int		nb;

	if (!str)
		return (NULL);
	i = 0;
	nb = ctn_chcknchar(c, str);
	while (i < nb)
	{
		str = rep_ctoi(str, c, apn);
		i++;
	}
	return (str);
}
