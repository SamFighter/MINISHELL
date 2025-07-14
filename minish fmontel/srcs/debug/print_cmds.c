/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:26:59 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:13:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/debug.h"

/**
 * Print the whole content of a cmd (t_cmd *) in the console
 * - If 'title' is set to 1, print the title
 */
void	print_cmds(t_cmd *cmds, int title)
{
	int	i;

	i = 0;
	if (!cmds)
		return (utl_putchar('\n'));
	if (title == 1)
	{
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		ft_printf("    -------- DEBUG PRINT --------\n\n");
		ft_printf("	    ---- CMDS ----\n\n");
	}
	while (cmds->next)
	{
		ft_printf(" * cmd nb %i:\n", i++);
		debug_cmd(cmds);
		cmds = cmds->next;
	}
	if (cmds)
	{
		ft_printf(" * cmd nb %i:\n", i++);
		debug_cmd(cmds);
	}
	if (title == 1)
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
}

/**
 * @brief Print the whole content of a cmd (t_cmd *) in the 
 * file-descriptor 'fd'
 * 
 * - If 'title' is set to 1, print the title
 */
void	fd_print_cmds(int fd, t_cmd *cmds, int title)
{
	int	i;

	i = 0;
	if (!cmds)
		return (utl_putchar_fd(fd, '\n'));
	if (title == 1)
	{
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		fd_printf(fd, "    -------- DEBUG PRINT --------\n\n");
		fd_printf(fd, "	    ---- CMDS ----\n\n");
	}
	while (cmds->next)
	{
		fd_printf(fd, " * cmd nb %i:\n", i++);
		fd_debug_cmd(fd, cmds);
		cmds = cmds->next;
	}
	if (cmds)
	{
		fd_printf(fd, " * cmd nb %i:\n", i++);
		fd_debug_cmd(fd, cmds);
	}
	if (title == 1)
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
}

/**
 * @brief Print the whole content of a cmd (t_cmd *) in the
 * console and then save it into a log file
 */
void	log_cmds(t_cmd *cmds, int save)
{
	int	fd;

	if (!cmds)
	{
		ft_printf("	\033[1;93mNo Cmd list to print, aborted\033[0m\n\n");
		return ;
	}
	print_cmds(cmds, 1);
	if (save)
	{
		fd = open("cmds.log", O_CREAT | O_TRUNC | O_RDWR, 0777);
		if (fd == -1)
		{
			ft_printf("	\033[1;31mCmds Log could not be saved\033[0m\n\n");
			return ;
		}
		fd_print_cmds(fd, cmds, 1);
		ft_printf("	\033[1;92mCmds Log saved sucessfully\033[0m\n\n");
	}
}
