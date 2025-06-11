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


static char *build_path(char *env_path, int end, int start, char *cmd)
{
    char *dir;
    char *tmp;
    char *full_path;
    int len;

    len = start - end;
    dir = str_substr(env_path, end, len);
    if (!dir)
        return (NULL);
    tmp = str_join(dir, "/");
    free(dir);
    if (!tmp)
        return (NULL);
    if (check_path(tmp, cmd) == 0)
    {
        full_path = str_join(tmp, cmd);
        free(tmp);
        return (full_path);
    }
    free(tmp);
    return (NULL);
}

/**
 * @param str_envp 
 * @param cmdlist 
 * @return char* 
 */
char *get_path(char *str_envp, t_cmdlist *cmdlist)
{
    char *path;
    int start;
    int end;

    if (!str_envp)
        return (str_dup("./"));
    start = 0;
    end = 0;
    while (str_envp[start])
    {
        if (str_envp[start] == ':' || str_envp[start + 1] == '\0')
        {
            if (str_envp[start + 1] == '\0')
                start++;
            path = build_path(str_envp, end, start, cmdlist->cmds->str_cmd);
            if (path != NULL)
                return (path);
            end = start + 1;
        }
        start++;
    }
    return (str_dup(cmdlist->cmds->str_cmd));
}

/**
 * @param path 
 * @param cmd 
 * @return int 
 */
int	check_path(char *path, char *cmd)
{
	char	*full_path;
	int		result;
	int		len;

	result = 1;
	len = str_len(path);
	if (path[len - 1] != '/')
		path = str_join(path, "/");
	full_path = str_join(path, cmd);
	if (full_path && access(full_path, X_OK) == 0)
		result = 0;
	free(full_path);
	return (result);
}

bool    search_pipe(t_token *tok)
{
    t_token *tmp;
    
    tmp = tok;
    while (tmp)
    {
        if (tmp->type == PIPE)
            return (true);
        tmp = tmp->next;
    }
    return (false);
}

int		check_cmd(t_controller *cont)
{
	char	*abs_path;
	char	*path_env;

	path_env = env_cut(search_envp("PATH", cont->env));
	abs_path = get_path(path_env, &cont->cmdlist);
	free(path_env);
	if (abs_path == cont->cmdlist.cmds->str_cmd)
	{
		ft_printf("%s : command not found", abs_path);
		if (abs_path != NULL)
			free(abs_path);
		return (-1);
	}
	free(abs_path);
	return (0);
}
