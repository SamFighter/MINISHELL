/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:27:58 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/16 03:08:03 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Built-in function that reproduce the pwd bash command
 * in short he will print the position of the actual path you're in
 * 
 * @return int 
 */
int	ft_pwd(t_controller *cont)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		if (cont->pwd)
			ft_printf("%s\n", cont->pwd);
		else
			perror("pwd");
		return (1);
	}
}
