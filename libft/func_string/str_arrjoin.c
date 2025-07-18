/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:20:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/16 03:01:57 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Join the arrays of strings (char **) 's1 and 's2' and
 * return the joined string
 */
char	**str_arrjoin(char **arr1, char **arr2)
{
	int		i;
	int		len;
	char	**new;

	if (!arr1 && !arr2)
		return (NULL);
	if (!arr1)
		return (str_arrdup(arr2));
	if (!arr2)
		return (str_arrdup(arr1));
	i = 0;
	len = str_arrlen((const char **) arr2);
	new = NULL;
	while (i < len)
		new = str_arrrep_nset(new, arr2[i++]);
	return (new);
}

/**
 * @brief Join the arrays of strings (char **) 's1 and 's2' and
 * return the joined string and free 'arr1'
 */
char	**str_arrrejoin(char **arr1, char **arr2)
{
	char	**new;

	new = str_arrjoin(arr1, arr2);
	utl_super_free((void **)arr1);
	return (new);
}
