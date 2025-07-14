/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_dbl_arrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:23:06 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/06 16:02:52 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return the number of int arrays (int *) in the double array 'tab_str'
 */
int	utl_dbl_arrlen(void **tab_str)
{
	int	y;

	if (!tab_str)
		return (0);
	y = 0;
	while (tab_str[y])
		y++;
	return (y);
}
