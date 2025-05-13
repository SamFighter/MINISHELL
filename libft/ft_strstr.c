/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:04:58 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/28 17:12:22 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

/**
 * @brief Search for a string (char *) 'to_find' in the string 'str'
 * and return the adress of the start of the string if found, else return NULL
 */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
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
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	finder;

	i = 0;
	finder = ft_strlen(little);
	if (finder == 0)
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
			j = 0;
		}
		i++;
	}
	return (NULL);
}
