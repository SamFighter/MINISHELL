/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:35 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/31 18:17:55 by salabbe          ###   ########.fr       */
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
int	exec_builtins(t_controller *cont, char **args)
{
	if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "cd", INT_MAX))
		ft_cd(args, cont);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "echo", INT_MAX))
		ft_echo(args);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "env", INT_MAX))
		ft_env(cont);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "export", INT_MAX))
		ft_export(cont, args);
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "pwd", INT_MAX))
		ft_pwd();
	else if (!str_ncmp(cont->cmdlist.cmds->str_cmd, "unset", INT_MAX))
		ft_unset(args, cont);
	else
		return (1);
}

/**
 * @brief functionnal execution (without pipe), need some adjustement
 * 
 */
int	exec(t_controller *cont)
{
	t_cmd	*tmp;
	int 	*pip;

	tmp = cont->cmdlist.cmds;
	pip = cont->pip;
	cont->cmdlist.cmds->cmd_args = str_rarrdup_nset(cont->cmdlist.cmds->args, cont->cmdlist.cmds->str_cmd);
	if (search_pipe(cont->cmdlist.cmds->tokens) == false)
	{
		if (is_builtin(cont->cmdlist.cmds) == true)
			return (exec_builtins(cont, cont->cmdlist.cmds->args));
		else
			return (exec_cmd(cont));
	}
	else
	{
		printf("pas encore fait les pipes connard\n");
		return (0);
	}
	return (0);
}

/**
 * @brief Execute une ligne de commande qui n'a aucun pipe
 * 
 * @param cont 
 * @param cmds 
 * @param pip 
 */
int exec_cmd(t_controller *cont)
{
	int		pid;
	int		status;
	char	*path;
	char 	*abs_path;

	pid = fork();
	status = 0;
	if (pid < 0)
		return (1);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		path = env_cut(search_envp("PATH=", cont->env));
		abs_path = get_path(path, &cont->cmdlist);
		if (abs_path == cont->cmdlist.cmds->str_cmd)
			ft_printf("%s : command not found\n", abs_path);
		if (execve(abs_path, cont->cmdlist.cmds->cmd_args, cont->env) == -1)
			return (1);
	} 
	return (0);
}
