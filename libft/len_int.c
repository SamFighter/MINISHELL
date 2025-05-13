/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:21:44 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/28 17:42:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return the number of digits in 'n'
 */
int	len_int(long int n)
{
	int		size;

	size = 1;
	if (n == 0)
		return (size);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n < 10 && n > 0)
		return (size);
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
