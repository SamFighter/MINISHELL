/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:13:43 by fmontel          ###   ########.fr       */
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
		cont.excode = sig_value(cont.excode);
		if (!line || cont.excode == 139)
			closing(&cont);
		if (str_len(line) != 0)
		{
			tokenizer(line, &cont);
			controller_exec(&cont);
			if (cont.cmdlist.invalid != -1)
				add_history(line);
		}
		cmdlist_reset(&cont.cmdlist);
	}
	return (cont.excode % 256);
}
