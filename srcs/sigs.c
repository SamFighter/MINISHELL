/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:41:18 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/17 07:37:51 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	sig_int(int sig)
{
	(void) sig;
	g_sig = SIGINT;
	fd_printf(1, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sig_int_norl(int sig)
{
	(void) sig;
	g_sig = SIGINT;
}

void	sig_segv(int sig)
{
	(void) sig;
	g_sig = SIGSEGV;
	fd_printf(2, "Segmentation fault\n");
	exit(11);
}

void	sig_abrt(int sig)
{
	(void) sig;
	g_sig = SIGABRT;
	fd_printf(1, "abort\n");
}

int	sig_value(int prev_value)
{
	int	sig;

	sig = g_sig;
	g_sig = 0;
	if (sig == SIGINT)
		return (130);
	if (sig == SIGSEGV)
		return (139);
	if (sig == SIGABRT)
		return (134);
	if (sig != 0)
		return (sig);
	return (prev_value);
}
