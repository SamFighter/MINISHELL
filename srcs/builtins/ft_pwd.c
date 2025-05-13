/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:27:58 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 18:48:09 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Built-in function that reproduce the pwd bash command
 * in short he will print the position of the actual path you're in
 * 
 * @return int 
 */
int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		perror(cwd);
		return (1);
	}
}
