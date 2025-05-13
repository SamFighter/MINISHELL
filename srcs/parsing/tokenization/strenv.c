/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:24:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 14:12:04 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/headers/libft.h"

/**
 * Return an environment-variable name as a string (char *), NULL if none
 */
char	*strenv(char *str, int start)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	s = NULL;
	start = ft_strlnchr(str, '$', start);
	while (str[i + start] && (ft_isalnum((int)str[i + start])
			|| str[i + start] == '_' || (i == 0 && str[i + start] == '$')))
		i++;
	if (i > 0)
		s = ft_substr(str, start, i);
	return (s);
}

/**
 * Return all environment-variable name as a string (char **), NULL if none
 */
char	**mult_strenv(char **env, char *str)
{
	int	start;

	if (!str)
		return (NULL);
	start = -1;
	ft_printf("%s", str);
	while (start != -1)
	{
		start = ft_strlnchr(str, '$', start + 1);
		if (start != -1)
			env = strarr_dupnset(env, strenv(str, start));
	}
	return (env);
}
