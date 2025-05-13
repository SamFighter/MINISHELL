/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:35 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 19:38:20 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
			if (check_path(path, cmdlist->cmds->str_cmd) == 1)
				return (str_join(path, cmdlist->cmds->str_cmd));
			end = start + 1;
		}
		start++;
	}
	return (str_join(path, str_envp));
}

int	check_path(char *path, char *cmd)
{
	if (access(str_join(path, cmd), X_OK))
		return (0);
	else 
		return (1);
}

/**
 * @brief tryin a few things rn
 * 
 */
void exec_cmd(t_controller *cont)
{
	int		pid;
	int		status;
	char 	*abs_path;
	char 	*path;

	pid = fork();
	status = 0;
	if (pid < 0)
		return ;
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		// is_builtin(cont->cmdlist.cmds);
		path = env_cut(search_envp("PATH=", cont->env));
		abs_path = get_path(path, &cont->cmdlist);
		int y = 0;
		while(cont->cmdlist.cmds->args[y])
			printf("%s\n", cont->cmdlist.cmds->args[y++]);
		printf("%s\n", cont->cmdlist.cmds->str_cmd);
		if (execve(abs_path, &cont->cmdlist.cmds->str_cmd, cont->env) == -1)
			return ;
		exit(EXIT_FAILURE);
	} 
}