/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 18:41:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_child_status(t_controller *cont, int pid, int status,
	int last_pid)
{
	if (pid == last_pid)
	{
		if (WIFEXITED(status))
			cont->excode = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			cont->excode = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGQUIT)
				ft_printf("Quit (core dumped)\n");
			else if (WTERMSIG(status) == SIGINT)
				ft_printf("\n");
		}
	}
}
