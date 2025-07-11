/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:39:19 by fmontel           #+#    #+#             */
/*   Updated: 2025/06/28 10:09:44 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Free the string (char *) s1 and return a duplicate of the string s2
 */
char	*str_rep(char *s1, char *s2)
{
	free(s1);
	return (str_dup(s2));
}
