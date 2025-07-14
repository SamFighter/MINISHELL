/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_llstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:04:58 by fmontel           #+#    #+#             */
/*   Updated: 2025/06/17 18:31:02 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Check if all the characters (char) from the 'start' position
 * in the string (char *) 'big' is exactly the same without knowing the len
 * as the string 'little', return 1 if true, else return 0
 */
int	str_nlstr(char *big, char *little, int start)
{
	size_t	i;
	size_t	len;

	len = str_len(little);
	if (!big || !little || len == 0)
		return (0);
	i = 0;
	if (big[start] == little[0])
	{
		while (big[start + i] == little[i] && big[start + i] != 0
			&& i != len)
			i++;
		if (little[i] == 0)
			return (1);
	}
	return (0);
}

/**
 * @brief Check if all the characters (char) from the 'start' position and
 * 'len' number of character in the string (char *) 'big' is exactly the same
 * as the string 'little', return 1 if true, else return 0
 */
int	str_llstr(char *big, char *little, size_t len, int start)
{
	size_t	i;

	if (!big || !little || len == 0)
		return (0);
	i = 0;
	if (big[start] == little[0])
	{
		while (big[start + i] == little[i] && big[start + i] != 0
			&& i != len)
			i++;
		if (little[i] == 0)
			return (1);
	}
	return (0);
}
