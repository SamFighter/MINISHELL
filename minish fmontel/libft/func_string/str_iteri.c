/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_iteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:39:39 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/06 15:33:26 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterate the function 'f' on every characterof the string (char *) 's'
 */
void	str_iteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}
