/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 14:09:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Replace a string (char *) 'rep' in a duplicate of the string
 * 'str' by the int 'apn'
 * @warning - Returns an error if 'str' is not malloc
 * @warning - 'str' is freed at the end
 */
char	*rep_atoi(char *str, char *rep, int apn)
{
	char	*s;
	char	*itoa;
	int		start;
	int		i;
	int		j;

	i = -1;
	j = -1;
	s = NULL;
	itoa = cnv_itoa(apn);
	start = str_lnstr(str, rep, 0);
	if (start == -1)
		return (str_dup(s));
	s = mem_calloc((str_len(str) + str_len(itoa)
				- str_len(rep) + 1), sizeof(char));
	while (str[++i] && i != start)
		s[i] = str[i];
	while (itoa[++j])
		s[i + j] = itoa[j];
	i--;
	while (str[++i + str_len(rep)])
		s[i + j] = str[i + str_len(rep)];
	s[i + j] = 0;
	free(str);
	return (s);
}

/**
 * @brief Replace every character 'c' in a duplicate of the string (char *)
 * 'str' by the int 'append'
 * @warning - 'str' is freed at the end
 */
char	*rep_mult_atoi(char *str, char *rep, int apn)
{
	int		i;
	int		nb;
	char	*itoa;

	if (!str)
		return (NULL);
	if (!rep)
		return (str);
	i = 0;
	nb = str_nstr(str, rep);
	itoa = cnv_itoa(apn);
	while (i < nb)
	{
		str = rep_atoa(str, rep, itoa);
		i++;
	}
	return (str);
}
