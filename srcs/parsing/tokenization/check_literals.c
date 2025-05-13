/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_literals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:50:01 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/29 19:21:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

/**
 * @brief Check if the character at the position 'pos' in the string (char *)
 * 'str' is a " or a '
 * 
 * If it is the case change the int 'literal' based on it's value
 */
int	check_literals(char *str, int pos, int literal)
{
	char	c;
	char	prev_c;

	c = str[pos];
	prev_c = 0;
	if (pos != 0)
		prev_c = str[pos - 1];
	if (literal_str(literal, pos, c, prev_c))
		return (1);
	else if (literal_chr(literal, pos, c, prev_c))
		return (2);
	else if (reset_literal(literal, c, prev_c))
		return (0);
	return (literal);
}

/**
 * Return 1 if the character 'c' is a "
 * - Return 0 if 'literal' = 0
 * - If the pos is not = 0, check if 'prev_c' = \\
 */
int	literal_str(int literal, int pos, char c, char prev_c)
{
	if (literal == 0 && c == '"'
		&& (pos == 0 || prev_c != '\\'))
		return (1);
	else
		return (0);
}

/**
 * Return 1 if the character 'c' is a '
 * - Return 0 if 'literal' = 0
 * - If the pos is not = 0, check if 'prev_c' = \\
 */
int	literal_chr(int literal, int pos, char c, char prev_c)
{
	if (literal == 0 && c == '\''
		&& (pos == 0 || prev_c != '\\'))
		return (1);
	else
		return (0);
}

/**
 * Return 1 if the character 'c' is a " or a '
 * - Return 0 if 'literal' = 0 OR if 'prev_c' = \\
 */
int	reset_literal(int literal, char c, char prev_c)
{
	if (((literal == 1 && c == '"')
			|| (literal == 2 && c == '\'')) && prev_c != '\\')
		return (1);
	else
		return (0);
}
