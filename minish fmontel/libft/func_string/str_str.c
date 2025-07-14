/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:04:58 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 15:59:28 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Search for a string (char *) 'to_find' in the string 'str'
 * and return the adress of the start of the string if found, else return NULL
 */
char	*str_str(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (NULL);
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[j + i] && to_find[j] == str[j + i])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Search for a string (char *) 'little' in 'len' number of
 * character in the string 'big' and return the adress of the
 * start of the string if found, else return NULL
 */
char	*str_lstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] != 0 && i != len)
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && big[i + j] != 0
				&& i + j != len)
				j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Search for every string (char *) 'little' in the string 'big'
 * and return the number of time the string 'little' was found
 */
int	str_nstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	nb;

	i = 0;
	nb = 0;
	if (!big || !little)
		return (nb);
	while (i < str_len(big))
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && big[i + j] != 0)
				j++;
			if (little[j] == 0)
			{
				nb++;
				i += j;
			}
		}
		i++;
	}
	return (nb);
}

/**
 * @brief Search for a string (char *) 'little' from the 'start' position
 * in the string 'big' and return the position of the
 * start of the string if found, else return -1
 */
int	str_lnstr(const char *big, const char *little, size_t start)
{
	size_t	i;
	size_t	j;

	i = start;
	if (!big || !little)
		return (-1);
	if (str_len(big) - start < str_len(little))
		return (-1);
	while (big[i] != 0)
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && big[i + j] != 0)
				j++;
			if (little[j] == 0)
				return (i);
			j = 0;
		}
		i++;
	}
	return (-1);
}
