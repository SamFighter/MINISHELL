/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_isascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:30:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:26:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return 'c' as an int if the input character is part of the ascii table,
 * else return 0
 */
int	ctn_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return ((int) c);
	return (0);
}
