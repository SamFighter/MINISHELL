/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_chckchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:33:30 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 03:16:40 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a 'c' character (char) is present in a string (char *)
 */
int	ctn_chckchar(char c, char const *str)
{
	int		i;

	i = 0;
	while (c != str[i] && str[i] != 0)
		i++;
	if (c == str[i])
		return (1);
	else
		return (0);
}

/**
 * Return how many 'c' character (char) is present in a string (char *)
 */
int	ctn_chcknchar(char c, char const *str)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			o++;
		i++;
	}
	return (o);
}
