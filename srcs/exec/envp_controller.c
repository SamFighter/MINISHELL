/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:36:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 18:58:08 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	make_env(t_controller *cont);
void	exit_make_env(t_controller *cont);

/**
 * Duplicate all environment variable or create necessary ones if none
 */
void	dup_env(t_controller *cont, char **envp)
{
	char	*str;

	if (!(*envp))
		return (make_env(cont));
	cont->env = str_arrdup(envp);
	if (!cont->env)
		exit_make_env(cont);
	str = search_envp("PWD=", cont->env);
	cont->pwd = env_cut(str);
	free(str);
	str = search_envp("OLDPWD=", cont->env);
	cont->old_pwd = env_cut(str);
	free(str);
}

/**
 * @brief Return the searched environment variable, NULL if not found
 * @warning returns it with the variable name and '=' symbol at the start
 */
char	*search_envp(char *str, char **envp)
{
	int		y;
	char	*s;
	int		len;

	if (!str || !envp)
		return (NULL);
	if (str[0] == '$')
		s = str_substr(str, 1, str_len(str) - 1);
	else
		s = str_dup(str);
	y = 0;
	len = str_len(s);
	while (envp[y])
	{
		if (!(str_llstr(envp[y], s, len, 0) && envp[y][len] == '='))
			y++;
		else
		{
			s = str_rep(s, envp[y]);
			return (s);
		}
	}
	free (s);
	return (NULL);
}

void	make_env(t_controller *cont)
{
	char	path[PATH_MAX];
	char	*tmp;

	tmp = getcwd(path, PATH_MAX);
	if (tmp == NULL)
	{
		free(tmp);
		exit_make_env(cont);
	}
	tmp = str_dup("OLDPWD=");
	if (!tmp)
		exit_make_env(cont);
	cont->env = mem_calloc(3, sizeof(char *));
	if (!cont->env)
		exit_make_env(cont);
	cont->env[0] = tmp;
	cont->env[1] = str_join("PWD=", path);
	if (!cont->env[1])
		exit_make_env(cont);
}

/**
 * @brief Returns a substring of the environment variable passed without
 * the variale name and '=' symbol
 */
char	*env_cut(char *str)
{
	int		i;
	char	*cut;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (str_dup(""));
	cut = str_substr(str, i + 1, str_len(str) - (i + 1));
	return (cut);
}

void	exit_make_env(t_controller *cont)
{
	controller_free(cont);
	fd_printf(1, "minihell: error while trying to create missing");
	fd_printf(1, "nessecary environment variables\n");
	abort();
}
