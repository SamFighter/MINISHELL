/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_tolower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:18 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 04:18:53 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Change the character to lower-case if it's an upper-case letter
 */
int	rep_tolower(int c)
{
	if (ctn_isupper(c))
		return (c + 32);
	return (c);
}
