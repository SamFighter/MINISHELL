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
    int len;

    if (!str_envp)
        return (str_dup("./"));
    start = 0;
    end = 0;
    while (str_envp[start])
    {
        if (str_envp[start] == ':' || str_envp[start + 1] == '\0')
        {
            len = start - end;
            path = str_substr(str_envp, end, len);
            if (!path)
                return NULL;
            path[len] = '/';
            if (check_path(path, cmdlist->cmds->str_cmd) == 0)
                return str_join(path, cmdlist->cmds->str_cmd);
            free(path);
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

	result = 1;
	full_path = str_join(path, cmd);
	if (!access(full_path, X_OK))
		result = 0;
	free(full_path);
	return (result);
}
/**
 * @param cont 
 * @param args 
 */
int	exec_builtins(int stou, t_controller *cont, char **args)
{
	(void) stou;
	if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "cd", INT_MAX))
		cont->excode = ft_cd(args, cont);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "echo", INT_MAX))
		cont->excode = ft_echo(args);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "env", INT_MAX))
		cont->excode = ft_env(cont);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "export", INT_MAX))
		cont->excode = ft_export(cont, args);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "pwd", INT_MAX))
		cont->excode = ft_pwd();
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "unset", INT_MAX))
		cont->excode = ft_unset(args, cont);
	return (0);
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

	path_env = env_cut(search_envp("PATH=", cont->env));
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
