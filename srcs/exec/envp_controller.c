/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:36:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/19 14:53:52 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int    dup_env(t_controller *cont, char **envp)
{
    if (!(*envp))
		return (make_env(cont)); 
	cont->env = str_arrdup(envp);
	cont->pwd = env_cut(search_envp("PWD", cont->env));
	cont->old_pwd = env_cut(search_envp("OLDPWD", cont->env));
	return (0);
}

char	*search_envp(char *str, char **envp)
{
	int		i;
	int		len;

	if (!str || !envp)
		return (NULL);
	if (str[0] == '$')
		str++;
	len = str_len(str);
	i = 0;
	while (envp[i])
	{
		if (!str_ncmp(envp[i], str, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	make_env(t_controller *cont)
{
	char	path[PATH_MAX];
	char	*tmp;

	tmp = str_dup("OLDPWD=");
	if (!tmp || getcwd(path, PATH_MAX) == NULL)
		exit (1);
	cont->env = mem_calloc(3, sizeof (char *));
	if (!cont->env)
		exit (1);
	cont->env[0] = tmp;
	cont->env[1] = str_join("PWD=", path);
	if (!cont->env[1])
		exit (1);
	return (0);
}
