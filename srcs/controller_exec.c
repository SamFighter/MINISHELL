/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:17:09 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 19:51:17 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	invalid_print(t_controller *controller);

/**
 * Execute command if there was no parsing error, else start an 'invalid print'
 */
void	controller_exec(t_controller *controller)
{
	if (controller->cmdlist.invalid != 0)
		invalid_print(controller);
	else
		exec_cmd(controller);
}

void	invalid_print(t_controller *controller)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (!line)
		{
			controller->excode = 2;
			break ;
		}
	}
	ft_printf("minihell: ");
	if (controller->cmdlist.invalid == 1)
		ft_printf("unexpected EOF while looking for matching `\"\'\n");
	else if (controller->cmdlist.invalid == 2)
		ft_printf("unexpected EOF while looking for matching `\'\'\n");
	ft_printf("minihell: syntax error: unexpected end of file\n");
}
