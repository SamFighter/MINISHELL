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

int	exec_builtins(t_controller *cont, char *cmd_name, char **args)
{
	if (!str_ncmp(cmd_name, "cd", INT_MAX))
		return (ft_cd(args, cont));
	else if (!str_ncmp(cmd_name, "echo", INT_MAX))
		return (ft_echo(args));
	else if (!str_ncmp(cmd_name, "env", INT_MAX))
		return (ft_env(cont));
	else if (!str_ncmp(cmd_name, "export", INT_MAX))
		return (ft_export(cont, args));
	else if (!str_ncmp(cmd_name, "pwd", INT_MAX))
		return (ft_pwd(cont));
	else if (!str_ncmp(cmd_name, "unset", INT_MAX))
		return (ft_unset(args, cont));
	else if (!str_ncmp(cmd_name, "exit", INT_MAX))
		return (ft_exit(cont, cont->cmdlist.cmds));
	return (0);
}
