/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_isprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:30:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:26:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return 'c' as an int if the input character 'c' is a printable ascii character
 * else return 0
 */
int	ctn_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return ((int) c);
	return (0);
}
