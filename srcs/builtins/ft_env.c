/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:50:32 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/16 10:38:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	no_args_env(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Print in the standar output the whole environment variables
 * 
 * @param cont 
 * @return int 
 */
int	ft_env(t_controller *cont)
{
	char	**env;
	int		y;

	env = cont->env;
	if (!env)
		return (0);
	y = 0;
	while (env[y] && no_args_env(env[y]) == 0)
	{
		ft_printf("%s\n", env[y]);
		y++;
	}
	return (0);
}
