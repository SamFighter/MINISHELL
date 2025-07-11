/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_atoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:26:14 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 17:51:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Replace a string (char *) 'rep' in a duplicate of the string
 * 'str' by the string 'apn'
 * @warning - Returns an error if 'str' is not malloc
 */
char	*rep_atoa(char *str, char *rep, char *apn)
{
	char	*s;
	int		start;
	int		i;
	int		j;

	i = -1;
	j = -1;
	s = NULL;
	start = str_lnstr(str, rep, 0);
	if (start == -1)
		return (str_dup(s));
	s = mem_calloc((str_len(str) + str_len(apn)
				- str_len(rep) + 1), sizeof(char));
	while (str[++i] && i != start)
		s[i] = str[i];
	while (apn[++j])
		s[i + j] = apn[j];
	i--;
	while (str[++i + str_len(rep)])
		s[i + j] = str[i + str_len(rep)];
	s[i + j] = 0;
	free(str);
	return (s);
}

/**
 * @brief Replace a string (char *) 'rep' in a duplicate of the string
 * 'str' by the string 'apn'
 * @warning - 'str' is freed at the end
 */
char	*rep_latoa(char *str, char *rep, char *apn, int start)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	s = NULL;
	len = str_len(str) + str_len(apn) - str_len(rep);
	if (len == 0 || start == -1)
		return (NULL);
	s = mem_calloc(len + 1, sizeof(char));
	while (str[++i] && i != start)
		s[i] = str[i];
	while (apn[++j])
		s[i + j] = apn[j];
	i--;
	while (str[++i + str_len(rep)])
		s[i + j] = str[i + str_len(rep)];
	s[i + j] = 0;
	free(str);
	return (s);
}

/**
 * @brief Replace every string (char *) 'rep' in a duplicate of
 * the string (char *) 'str' by the string 'apn'
 * @warning - 'str' is freed at the end
 */
char	*rep_mult_atoa(char *str, char *rep, char *apn)
{
	int		i;
	int		nb;

	if (!str)
		return (NULL);
	if (!rep)
		return (str);
	nb = str_nstr(str, rep);
	i = 0;
	if (nb == 0 || str_len(rep) > str_len(str))
		return (str);
	while (i < nb)
	{
		if (apn)
			str = rep_atoa(str, rep, apn);
		else
			str = rep_atoa(str, rep, "");
		i++;
	}
	if (str[0] == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
