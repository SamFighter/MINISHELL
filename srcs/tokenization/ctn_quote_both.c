/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctn_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:50:01 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 14:41:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Check if the character at the position 'pos' in the string (char *)
 * 'str' is a " or a ' AND if so will check if there is a closing quote
 */
int	ctn_quote_both(char *str, int pos, int in_quote)
{
	char	c;
	char	prev_c;
	int		quote;
	int		i;

	i = pos;
	quote = in_quote;
	if (!in_quote)
	{
		quote = ctn_quote(str, pos, 0);
		i++;
	}
	while (quote && str[i])
	{
		c = str[i];
		prev_c = str[i - 1];
		if (ctn_quotes(0, i, c, prev_c))
			return (1);
		else if (ctn_quotec(0, i, c, prev_c))
			return (2);
		i++;
	}
	return (0);
}
