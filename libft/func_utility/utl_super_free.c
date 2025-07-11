/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_super_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:32:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:00:27 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Free all the strings (char *) in the double string (char **) 'str'
 */
char	**utl_super_free(void **str)
{
	void	**orig_str;

	if (!str || !*str)
		return (NULL);
	orig_str = str;
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*str);
	*str = NULL;
	free(orig_str);
	return (NULL);
}

/**
 * Free 'len' number of int arrays (int *) in the int array (int **) 'id'
 */
int	**utl_super_free_int(int **id, int len)
{
	int	**orig_id;
	int	i;

	i = 0;
	if (!id || !*id)
		return (NULL);
	orig_id = id;
	while (i < len)
	{
		free(id[i]);
		i++;
	}
	free(orig_id);
	return (NULL);
}
