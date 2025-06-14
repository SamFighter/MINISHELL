/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:14:40 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/19 11:21:47 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Verify if in args their's '-n' flag and add true or false to the flag in ft_echo
 * 
 * @param str 
 * @return int 
 */
static int 	bool_new_line(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] && str[i] == '-')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (i == str_len(str))
			return (1);
	}
	return (0);

}

/**
 * @brief The core of the ft_echo function, with every info received, the will function write each args
 * 
 * @param args 
 * @param len 
 * @param y 
 * @param new_line 
 */
static void print_echo(char **args, int len, int y, bool new_line)
{
	while (args[y] && bool_new_line(args[y]))
	{
		y++;
		new_line = false;
	}
	while (y < len)
	{
		write(1, args[y], str_len(args[y]));
		if (y != len - 1)
			write(1, " ", 1);
		y++;
	}
	if (new_line)
		write(1, "\n", 1);
}
/**
 * @brief Print in the standard output the args
 * 
 * @param args 
 * @return int 
 */
int	ft_echo(char **args)
{
	int		len;
	int 	y;
	bool	new_line;

	len = 0;
	if (args == NULL)
	{
		ft_printf("\n");
		return (0);
	}
	while (args[len])
		len++;
	y = 0;
	new_line = true;
	print_echo(args, len, y, new_line);
	return (0);
}
