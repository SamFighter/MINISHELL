/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/19 14:35:06 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <signal.h>

int	g_sig;

/**
 * Free the controller of the program and all it's content
 */
void	controller_free(t_controller *cont)
{
	cmdlist_free(&cont->cmdlist);
	if (cont->pwd)
		free(cont->pwd);
	if (cont->old_pwd)
		free(cont->old_pwd);
	if (cont->env)
		utl_super_free((void **)cont->env);
}

int	main(int argc, char **argv, char **env)
{
	t_controller		cont;
	char				*line;
	char				*prompt;

	(void)argc;
	(void)argv;
	initializer(&cont, env);
	while (g_sig != EOF)
	{
		prompt = prompt_controller(cont.excode, cont.env);
		line = readline(prompt);
		free(prompt);
		if (g_sig == 130 || g_sig == 139)
			cont.excode = g_sig;
		if (!line)
			closing(&cont);
		if (str_len(line) != 0)
		{
			tokenizer(line, &cont);
			controller_exec(&cont);
			add_history(line);
		}
		cmdlist_reset(&cont.cmdlist);
	}
	return (cont.excode);
}
