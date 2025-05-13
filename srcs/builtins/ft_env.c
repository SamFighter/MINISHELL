/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:50:32 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/06 14:22:39 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Print in the standar output the whole environment variables
 * 
 * @param cont 
 * @return int 
 */
int	ft_env(t_controller *cont)
{
	char **env;
	int y;

	env = cont->env;
	if (!env)
		return (0);
	y = 0;
	while (env[y])
	{
		ft_printf("%s\n",env[y]);
		y++;
	}
	return (0);
}