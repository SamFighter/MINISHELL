/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:23:06 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/28 19:09:40 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return the number of int arrays (int *) in the double int array
 * (int **) 'tab_str'
 */
int	sf_tablen(char **tab_str)
{
	int	y;

	if (!tab_str)
		return (0);
	y = 0;
	while (tab_str[y])
		y++;
	return (y);
}
