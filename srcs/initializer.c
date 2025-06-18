/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:33:37 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/19 11:28:20 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_sig(void);
void	init_cont(t_controller *controller);

/**
 * Initialize values for the controller
 */
void	initializer(t_controller *controller, char **env)
{
	init_cont(controller);
	dup_env(controller, env);
	(void)env;
	init_sig();
}

void	init_sig(void)
{
	signal(SIGINT, &sig_int);
	// signal(SIGSEGV, &sig_segv);
	signal(SIGABRT, &sig_abrt);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * Initialize the controller of the program and all it's content to NULL
 */
void	init_cont(t_controller *controller)
{
	controller->excode = 0;
	controller->pwd = NULL;
	controller->old_pwd = NULL;
	controller->env = NULL;
	controller->cmdlist.tokens = tk_init();
	controller->cmdlist.cmds = init_cmd();
}
