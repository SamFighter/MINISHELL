/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:48:02 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <signal.h>

/**
 * Initialize the controller of the program and all it's content to NULL
 */
void	init_cont(t_controller *controller)
{
	controller->excode = 0;
	controller->pwd = NULL;
	controller->old_pwd = NULL;
	controller->env = NULL;
	controller->cmdlist.tokens = init_token();
	controller->cmdlist.cmds = init_cmd();
}

/**
 * Free the controller of the program and all it's content
 */
void	free_cont(t_controller *cont)
{
	free_cmdlist(&cont->cmdlist);
	if (cont->pwd)
		free(cont->pwd);
	if (cont->old_pwd)
		free(cont->old_pwd);
	if (cont->env)
		super_free((void **)cont->env);
}

/**
 * Exit the program cleanly and return 'excode'
 */
int	exit_cmd(t_controller *cont, int excode)
{
	rl_clear_history();
	free_cont(cont);
	exit (excode);
}

int	main(int argc, char **argv, char **env)
{
	t_controller		cont;
	char				*line;
	char				*prompt;

	(void)argc;
	(void)argv;
	init_cont(&cont);
	dup_env(&cont, env);
	while (1)
	{
		prompt = promt_controller(&cont);
		line = readline(prompt);
		free(prompt);
		if (!line)
			exit(0);
		tokenizer(line, &cont.cmdlist);
		add_history(line);
		exec_cmd(&cont);
		reset_cmdlist(&cont.cmdlist);
		cont.excode++;
		if (cont.excode > 4)
			cont.excode = 0;
		// if (cont.excode == 4)
		// 	exit_cmd(&cont, cont.excode);
	}
}
