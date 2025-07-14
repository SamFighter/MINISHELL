/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 18:41:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static char	*get_full_path(char *path, char *cmd)
{
	char	*tmp;
	char	*full_path;

	if (path[str_len(path) - 1] != '/')
		tmp = str_join(path, "/");
	else
		tmp = str_dup(path);
	if (!tmp)
		return (NULL);
	full_path = str_join(tmp, cmd);
	free(tmp);
	return (full_path);
}

int	check_path(char *path, char *cmd)
{
	char	*full_path;
	int		result;

	result = 1;
	if (!path || !cmd)
		return (1);
	full_path = get_full_path(path, cmd);
	if (full_path)
	{
		if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
			result = 0;
		free(full_path);
	}
	return (result);
}

int	check_cmd(t_controller *cont)
{
	char	*abs_path;
	char	*path_env;

	if (!cont || !cont->cmdlist.cmds || !cont->cmdlist.cmds->str_cmd)
		return (-1);
	path_env = search_envp("PATH", cont->env);
	abs_path = get_path(path_env, cont->cmdlist.cmds);
	if (!abs_path)
	{
		fd_printf(2, "%s: command not found\n", cont->cmdlist.cmds->str_cmd);
		return (-1);
	}
	free(abs_path);
	return (0);
}

void	handle_child_status(t_controller *cont, int pid, int status)
{
	if (pid == g_sig && WIFEXITED(status))
		cont->excode = WEXITSTATUS(status);
	else if (pid == g_sig && WIFSIGNALED(status))
		cont->excode = 128 + WTERMSIG(status);
}
