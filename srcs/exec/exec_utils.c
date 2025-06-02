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
	abs_path = get_path(path, cont->cmdlist);
	if (abs_path == cont->cmdlist.cmds->str_cmd)i
	{
		ft_printf("%s : command not found", abs_path);
		return (-1);
	}
	return (0);
}
