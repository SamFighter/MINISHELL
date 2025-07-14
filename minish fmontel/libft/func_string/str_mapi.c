/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:08:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 16:58:59 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*str_mapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc((str_len(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != 0)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
