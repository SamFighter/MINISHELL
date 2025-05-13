/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:36:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 15:36:33 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int    dup_env(t_controller *cont, char **envp)
{
	int	y;

	y = 0;
    if (!(*envp))
		return (make_env(cont)); 
	cont->env = strarr_dup(envp);
	cont->pwd = env_cut(search_envp("PWD=", cont->env));
	cont->old_pwd = env_cut(search_envp("OLDPWD=", cont->env));
	return (0);
}

char	*search_envp(char *str, char **envp)
{
	int		y;
	char	*s;
	
	if (!str || !envp)
		return (NULL);
	if (str[0] == '$')
		s = ft_substr(str, 1, ft_strlen(str) - 1);
	else
		s = ft_strdup(str);
	y = 0;
	while (envp[y])
	{
		if (!ft_strstr(envp[y], s))
			y++;
		else if (ft_strstr(envp[y], s))
		{
			s = ft_strdup(envp[y]);
			return (s);
		}
	}
	free (s);
	return (NULL);
}

int	make_env(t_controller *cont)
{
	char	path[PATH_MAX];
	char	*tmp;

	tmp = ft_strdup("OLDPWD=");
	if (!tmp || getcwd(path, PATH_MAX) == NULL)
		exit (1);
	cont->env = ft_calloc(3, sizeof (char *));
	if (!cont->env)
		exit (1);
	cont->env[0] = tmp;
	cont->env[1] = ft_strjoin("PWD=", path);
	if (!cont->env[1])
		exit (1);
	return (0);
}
