/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:48:38 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 18:56:14 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

bool	is_builtin(t_cmd *cmd)
{
	const char	*builtin[] = {"cd", "pwd", "echo", "exit", \
				"export", "env", "unset", NULL};
	int			y;

	y = 0;
	while (builtin[y])
	{
		if (str_cmp((char *) builtin[y], cmd->str_cmd) == 0)
			return (true);
		y++;
	}
	return (false);
}

int	prepare_builtin(t_controller *cont, t_cmd *cmd)
{
	int	stdout_backup;
	int	result;

	stdout_backup = -1;
	if (cmd->fd_out >= 0)
	{
		stdout_backup = dup(STDOUT_FILENO);
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
			return (1);
		close(cmd->fd_out);
	}
	result = exec_builtins(cont, cmd->str_cmd, cmd->args);
	if (stdout_backup >= 0)
	{
		dup2(stdout_backup, STDOUT_FILENO);
		close(stdout_backup);
	}
	return (result);
}

/**
 * @param cont 
 * @param args 
 * @param cmd_name
 */
int	exec_builtins(t_controller *cont, char *cmd_name, char **args)
{
	if (!str_ncmp(cmd_name, "cd", INT_MAX))
		cont->excode = ft_cd(args, cont);
	else if (!str_ncmp(cmd_name, "echo", INT_MAX))
		cont->excode = ft_echo(args);
	else if (!str_ncmp(cmd_name, "env", INT_MAX))
		cont->excode = ft_env(cont);
	else if (!str_ncmp(cmd_name, "export", INT_MAX))
		cont->excode = ft_export(cont, args);
	else if (!str_ncmp(cmd_name, "pwd", INT_MAX))
		cont->excode = ft_pwd();
	else if (!str_ncmp(cmd_name, "unset", INT_MAX))
		cont->excode = ft_unset(args, cont);
	else if (!str_ncmp(cmd_name, "exit", INT_MAX))
		cont->excode = ft_exit(cont, cont->cmdlist.cmds);
	return (cont->excode);
}
