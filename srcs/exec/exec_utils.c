/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:48:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/20 15:25:57 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static char	*create_full_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = str_join(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = str_join(tmp, cmd);
	free(tmp);
	return (full_path);
}

static char	*build_path(char *env_path, int start, int end, char *cmd)
{
	char	*dir;
	char	*full_path;
	int		len;

	len = end - start;
	if (len <= 0)
		return (NULL);
	dir = str_substr(env_path, start, len);
	if (!dir)
		return (NULL);
	full_path = create_full_path(dir, cmd);
	free(dir);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*search_in_path(char *str_envp, char *cmd)
{
	char	*path;
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (str_envp[i])
	{
		if (str_envp[i] == ':' || str_envp[i + 1] == '\0')
		{
			if (str_envp[i + 1] == '\0')
				i++;
			path = build_path(str_envp, start, i, cmd);
			if (path != NULL)
				return (path);
			start = i + 1;
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char *str_envp, t_cmd *cmd)
{
	if (!str_envp || !cmd || !cmd->str_cmd)
		return (NULL);
	return (search_in_path(str_envp, cmd->str_cmd));
}
