/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:03:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/17 02:03:31 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Return a duplicate of the string (char *) 'str' with the
 * character 'c' added at the end
 * @warning free 'str' at the end
 */
char	*str_addc(char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!str && !c)
		return (NULL);
	if (str && !c)
		return (str);
	if (!str && c)
	{
		s = malloc(2 * sizeof(char));
		s[0] = c;
		s[1] = 0;
		return (s);
	}
	s = malloc((str_len(str) + 2) * sizeof(char));
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = 0;
	free(str);
	return (s);
}
