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
char    *get_path(char *str_envp, t_cmdlist *cmdlist)
{
	char	*path;
	int     start;
	int     end;
	int 	len;

	if (!str_envp)
		return ("./");
	start = 0;
	end = 0;
	while (str_envp[start])
	{
		if (str_envp[start] == ':' || str_envp[start + 1] == 0)
		{
			path = str_substr(str_envp, end, start - end);
			if (!path)
				perror(path);
			len = str_len(path);
			path[len] = '/';
			if (check_path(path, cmdlist->cmds->str_cmd) == 0)
				return (str_join(path, cmdlist->cmds->str_cmd));
			end = start + 1;
		}
		start++;
	}
	return (cmdlist->cmds->str_cmd);
}
/**
 * @param path 
 * @param cmd 
 * @return int 
 */
int	check_path(char *path, char *cmd)
{
	if (!access(str_join(path, cmd), X_OK))
		return (0);
	else 
		return (1);
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

int		check_cmd(char *path, t_controller *cont)
{
	char *abs_path;

	path = env_cut(search_envp("PATH=", cont->env));
	abs_path = get_path(path, &cont->cmdlist);
	if (abs_path == cont->cmdlist.cmds->str_cmd)
	{
		ft_printf("%s : command not found", abs_path);
		return (-1);
	}
	return (0);
}
