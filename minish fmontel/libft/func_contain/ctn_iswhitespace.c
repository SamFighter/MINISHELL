/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_iswhitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:30:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:27:00 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return 'c' as an int if the input character is a white space,
 * else return 0
 */
int	ctn_iswhitespace(int c)
{
	if ((c == ' ' || c == '\t' || c == '\r')
		|| c == '\n' || c == '\v' || c == '\f')
		return ((int) c);
	return (0);
}
