/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sarr_add_if_none.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:58:39 by fmontel           #+#    #+#             */
/*   Updated: 2025/06/28 13:43:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Add a string (char *) to an array of string (char **) if it is not
 * already present in said array of string
 */
char	**sarr_add_if_none(char **sarr, char *s)
{
	int		i;

	i = 0;
	while (sarr[i])
	{
		if (sarr[i] != s)
			i++;
		else
			return (sarr);
	}
	return (str_arrdup_nset(sarr, s));
}
