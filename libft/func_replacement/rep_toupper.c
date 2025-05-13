/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_toupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:18 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 04:18:54 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Change the character to upper-case if it's an lower-case letter
 */
int	rep_toupper(int c)
{
	if (ctn_islower(c))
		return (c - 32);
	return (c);
}
