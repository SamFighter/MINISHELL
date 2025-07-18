/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:11 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/10 14:15:31 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/**
 * Exit the program and return 'excode'
 * - Change the excode depending on signals if needed
 */
void	closing(t_controller *cont)
{
	fd_printf(1, "exit\n");
	controller_free(cont);
	exit(cont->excode % 256);
}
