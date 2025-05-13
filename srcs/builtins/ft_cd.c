/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:09:29 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 15:34:55 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_cd(char *path, t_controller *cont)
{
	if (!path)
		return (1);
	if (chdir(path) == 0)
	{
		free(cont->old_pwd);
		cont->old_pwd = NULL;
		cont->old_pwd = env_cut(search_envp(cont->pwd, cont->env));
		free(cont->pwd);
		cont->pwd = NULL;
		cont->pwd = getcwd(cont->pwd, PATH_MAX);
	}
	return (0);
}