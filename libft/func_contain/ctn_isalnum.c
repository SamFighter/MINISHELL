/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_isalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:30:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:25:19 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Return 'c' as an int if the input character is alphabetical or numerical,
 * else return 0
 */
int	ctn_isalnum(int c)
{
	if (ctn_isalpha(c) || ctn_isdigit(c))
		return ((int) c);
	return (0);
}
