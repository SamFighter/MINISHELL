/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_isalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:30:38 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 13:25:56 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Return 'c' as an int if the input character is alphabetical,
 * else return 0
 */
int	ctn_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return ((int) c);
	return (0);
}

/**
 * Return 'c' as an int if the input character is an upper-case alphabetical,
 * else return 0
 */
int	ctn_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ((int) c);
	return (0);
}

/**
 * Return 'c' as an int if the input character is an lower-case alphabetical,
 * else return 0
 */
int	ctn_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((int) c);
	return (0);
}
