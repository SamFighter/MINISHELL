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
 * 'str' is a " or a '
 * 
 * If it is the case change the int 'literal' based on it's value
 */
int	ctn_quote(char *str, int pos, int quote)
{
	char	c;
	char	prev_c;

	c = str[pos];
	prev_c = 0;
	if (pos != 0)
		prev_c = str[pos - 1];
	if (ctn_quotes(quote, pos, c, prev_c))
		return (1);
	else if (ctn_quotec(quote, pos, c, prev_c))
		return (2);
	else if (reset_quote(quote, c, prev_c))
		return (0);
	return (quote);
}

/**
 * @return
 * 1 if the character 'c' = " and 'quote' = 0
 * 
 * 1 if the pos = 0 and if 'prev_c' != \\
 * 
 * else 0
 */
int	ctn_quotes(int quote, int pos, char c, char prev_c)
{
	if (quote == 0 && c == '"'
		&& (pos == 0 || prev_c != '\\'))
		return (1);
	else
		return (0);
}

/**
 * @return
 * 1 if the character 'c' = ' and 'quote' = 0
 * 
 * 1 if the pos = 0 and if 'prev_c' != \\
 * 
 * else 0
 */
int	ctn_quotec(int quote, int pos, char c, char prev_c)
{
	if (quote == 0 && c == '\''
		&& (pos == 0 || prev_c != '\\'))
		return (1);
	else
		return (0);
}

/**
 * Return 1 if the character 'c' is a " or a '
 * - Return 0 if 'quote' = 0 OR if 'prev_c' = \\
 */
int	reset_quote(int quote, char c, char prev_c)
{
	if (((quote == 1 && c == '"')
			|| (quote == 2 && c == '\'')) && prev_c != '\\')
		return (1);
	else
		return (0);
}
