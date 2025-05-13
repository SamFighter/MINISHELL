/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:11 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 15:51:25 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/**
 * Exit the program and return 'excode'
 * - Change the excode depending on signals if needed
 */
void	closing(t_controller *cont)
{
	if (g_sig == 130)
		cont->excode = 130;
	if (g_sig == 139)
		cont->excode = 139;
	fd_printf(1, "exit\n");
	rl_clear_history();
	controller_free(cont);
	exit(cont->excode);
}
