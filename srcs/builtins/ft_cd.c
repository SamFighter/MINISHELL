/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:09:29 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/19 14:28:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	update_oldpwd(t_controller *cont, char *old_pwd)
{
	char *tmp;

	free(cont->old_pwd);
	cont->old_pwd = str_dup(old_pwd);
	tmp = str_join("OLDPWD=", old_pwd);
	exportation(tmp, cont);
	free(tmp);
}
/**
 * @brief Basic cd function to move between directories, and update pwd and old_pwd
 * 
 * @param args 
 * @param cont 
 * @return int 
 */
int	ft_cd(char **args, t_controller *cont)
{
	int		rtn_chdir;
	char	*old_pwd;

	if (!args || !args[0])
		return (1);
	old_pwd = getcwd(NULL, PATH_MAX);
	rtn_chdir = chdir(args[0]);
	if (rtn_chdir == -1)
	{
		perror(args[0]);
		free(old_pwd);
		return (1);
	}
	update_oldpwd(cont, old_pwd);
	free(old_pwd);
	free(cont->pwd);
	cont->pwd = getcwd(NULL, PATH_MAX);
	return (0);
}
