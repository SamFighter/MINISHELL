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

char	*env_cut(char *str)
{
	int		i;
	char	*cut;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '=')
		i++;
	cut = str_substr(str, i + 1, str_len(str) - (i + 1));
	return (cut);
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

int		prepare_builtin(t_controller *cont, t_cmd *cmd)
{
	int	stout;

	stout = -1;
	if (cmd->fd_out >= 0)
	{
	  stout = dup(1);
	  dup2(cmd->fd_out, 1);
	}
	exec_builtin(stout, data, cmd);
	if (cmd->fd_out >= 0)
	{
	  dup2(stout, 1);
	  close(stout);
	}
	return (0);
}

