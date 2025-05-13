/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:50:01 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:21:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * @brief Return 1 if the character at the position 'pos' in the string
 * (char *) 'str' is a |, < or >
 * 
 * Will return 0 in spceific cases: if the previous character is NULL,
 * if the previous character is the same as the one at 'pos'
 * or if 'str[pos]' is NULL 
 */
int	check_symbols(char *str, int pos)
{
	char	c;
	char	prev_c;

	c = str[pos];
	prev_c = 0;
	if (pos != 0)
		prev_c = str[pos - 1];
	if ((c == '|' || c == '<' || c == '>') && prev_c != 0
		&& c != prev_c && !ft_iswhitespace(prev_c))
		return (1);
	if ((prev_c == '|' || prev_c == '<' || prev_c == '>') && c != 0
		&& prev_c != c && !ft_iswhitespace(c))
		return (1);
	else
		return (0);
}

/**
 * @brief Return 1 if the character at the position 0 in the string
 * (char *) 'str' is a |, < or >
 */
int	check_symbols_token(char *str)
{
	char	c;

	c = str[0];
	if (c == '|' || c == '<' || c == '>')
		return (1);
	else
		return (0);
}
