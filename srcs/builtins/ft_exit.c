/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:51:02 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/16 05:56:05 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	print_error_exit(t_cmd *cmd)
{
	fd_printf(2, "minihell: exit: %s", cmd->args[0]);
	fd_printf(2, ": numeric argument required\n");
}

static int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_exit(t_controller *cont, t_cmd *cmd)
{
	long	code;

	if (!cmd->next)
		utl_putstr_fd("exit\n", 2);
	if (cmd->args && cmd->args[0])
	{
		if (!is_num(cmd->args[0]))
		{
			print_error_exit(cmd);
			controller_free(cont);
			exit(2);
		}
		if (cmd->args[1])
		{
			utl_putstr_fd("minishell: exit: too many arguments\n", 2);
			cont->excode = 1;
			return (1);
		}
		code = ft_atol(cmd->args[0]);
		controller_free(cont);
		exit((unsigned char)code);
	}
	controller_free(cont);
	exit(0);
}
