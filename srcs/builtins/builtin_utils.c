/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:48:38 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/15 09:26:05 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char *env_cut(char *str)
{
	int i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		return (str + i + 1);
	return (NULL);
}

bool	is_builtin(t_cmd *cmd)
{
	const char	*builtin[] = {"cd", "pwd", "echo", "exit", \
				"export", "env", "unset", NULL};
	int			y;

	y = 0;
	while (builtin[y])
	{
		if (str_strcmp((char *) builtin[y], cmd->str_cmd) == 0)
			return (true);
		y++;
	}
	return (false);
}

int prepare_builtin(t_controller *cont, t_cmd *cmd)
{
    int stout;

    stout = -1;
    if (cmd->fd_out >= 0)
    {
        stout = dup(1);
        dup2(cmd->fd_out, 1);
    }
    exec_builtins(stout, cont, cmd->cmd_args[0], cmd->args);
    if (cmd->fd_out >= 0)
    {
        dup2(stout, 1);
        close(stout);
    }
    return (0);
}

/**
 * @param cont 
 * @param args 
 * @param cmd_name
 */
int exec_builtins(int stou, t_controller *cont, char *cmd_name, char **args)
{
    (void)stou;
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
    return (0);
}
