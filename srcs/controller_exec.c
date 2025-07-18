/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:17:09 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/17 11:18:11 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	invalid_print(t_controller *controller);
void	invalid_print2(t_controller *controller);

/**
 * Execute command if there was no parsing error, else start an 'invalid print'
 */
void	controller_exec(t_controller *controller)
{
	signal(SIGINT, sig_int_norl);
	if (controller->cmdlist.invalid == -1)
		return ;
	if (controller->cmdlist.invalid != 0)
	{
		invalid_print(controller);
		return ;
	}
	controller->excode = process_commands(controller);
	if (controller->excode == 2)
		return ;
	exec(controller);
	signal(SIGINT, sig_int);
}

void	invalid_print(t_controller *controller)
{
	controller->excode = 2;
	if (controller->cmdlist.invalid <= 2)
	{
		fd_printf(2, "minihell: ");
		if (controller->cmdlist.invalid == 1)
			fd_printf(2, "unexpected EOF while looking for matching `\"\'\n");
		else if (controller->cmdlist.invalid == 2)
			fd_printf(2, "unexpected EOF while looking for matching `\'\'\n");
		fd_printf(2, "minihell: syntax error: unexpected end of file\n");
	}
	else if (controller->cmdlist.invalid == 3)
		fd_printf(2, "minihell: syntax error near unexpected token `<'\n");
	else if (controller->cmdlist.invalid == 4)
		fd_printf(2, "minihell: syntax error near unexpected token `<<'\n");
	else if (controller->cmdlist.invalid == 5)
		fd_printf(2, "minihell: syntax error near unexpected token `>'\n");
	else if (controller->cmdlist.invalid == 6)
		fd_printf(2, "minihell: syntax error near unexpected token `>>'\n");
	else if (controller->cmdlist.invalid == 7)
		fd_printf(2, "minihell: syntax error near `|'\n");
	else if (controller->cmdlist.invalid == 8)
		fd_printf(2,
			"minihell: syntax error near unexpected token `newline'\n");
	else
		invalid_print2(controller);
}

void	invalid_print2(t_controller *controller)
{
	if (controller->cmdlist.invalid == 9)
	{
		fd_printf(2, "minihell: : No such file or directory\n");
		controller->excode = 1;
	}
	else if (controller->cmdlist.invalid == 99)
		fd_printf(2, "minihell: : command not found\n");
}
