/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:41:18 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/14 13:31:53 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	sig_int(int sig)
{
	(void) sig;
	g_sig = 130;
	fd_printf(1, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// void	sig_segv(int sig)
// {
// 	(void) sig;
// 	g_sig = 139;
// 	fd_printf(2, "Segmentation fault\n");
// 	exit(11);
// }

void	sig_abrt(int sig)
{
	(void) sig;
	g_sig = SIGABRT;
	fd_printf(1, "abort\n");
}
