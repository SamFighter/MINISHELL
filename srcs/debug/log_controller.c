/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:21:00 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 14:07:07 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/debug.h"

/**
 * @brief Print the whole content of a controller (t_controller *) in the
 * console and then save it into a log file
 */
void	log_controller(t_controller *controller, int save)
{
	int				fd;

	if (!controller)
	{
		ft_printf("	\033[1;93mNo Controller to print, aborted\033[0m\n\n");
		return ;
	}
	print_controller(controller);
	if (save)
	{
		fd = open("controller.log", O_CREAT | O_TRUNC | O_RDWR, 0777);
		if (fd == -1)
		{
			ft_printf("	\033[1;31mController Log could not be saved\033[0m");
			ft_printf("\n\n");
			return ;
		}
		fd_print_controller(fd, controller);
		ft_printf("	\033[1;92mController Log saved sucessfully\033[0m\n\n");
	}
}

/**
 * @brief Print the whole content of a controller (t_controller *) in the 
 * file-descriptor 'fd'
 */
void	fd_print_controller(int fd, t_controller *controller)
{
	t_controller	*cont;

	cont = controller;
	fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
	fd_printf(fd, "    -------- DEBUG FULL PRINT --------\n\n");
	fd_printf(fd, " * env     :\n%S\n", cont->env);
	fd_printf(fd, " * pwd     : %s\n", cont->pwd);
	fd_printf(fd, " * old_pwd : %s\n", cont->old_pwd);
	fd_printf(fd, " * excode  : %i\n", cont->excode);
	fd_printf(fd, "\n	     ---- CMDLIST ----\n\n");
	fd_print_cmdlist(fd, &cont->cmdlist, 0);
	tk_tostart(&controller->cmdlist.tokens);
	tk_tostart(&controller->cmdlist.cmds->tokens);
	fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
}

/**
 * @brief Print the whole content of a cmdlist (t_cmdlist *) in the 
 * file-descriptor 'fd'
 * 
 * - If 'title' is set to 1, print the title
 */
void	fd_print_cmdlist(int fd, t_cmdlist *cmdlist, int title)
{
	if (!cmdlist)
		return (utl_putchar('\n'));
	if (title == 1)
	{
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		fd_printf(fd, "    -------- DEBUG PRINT --------\n\n");
		fd_printf(fd, "	     ---- CMDLIST ----\n\n");
	}
	fd_printf(fd, "	       --- TOKEN ---\n\n");
	fd_print_tokens(fd, cmdlist->tokens, 0);
	fd_printf(fd, "	        --- CMD ---\n\n");
	fd_print_cmds(fd, cmdlist->cmds, 0);
	if (title == 1)
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
}

void	fd_debug_cmd(int fd, t_cmd *cmd)
{
	if (!cmd)
		return (utl_putchar_fd('\n', fd));
	fd_print_tokens(fd, cmd->tokens, 0);
	fd_printf(fd, "    * str cmd   : %s\n", cmd->str_cmd);
	fd_printf(fd, "    * infiles   :\n%S\n\n", cmd->infiles);
	fd_printf(fd, "    * outfiles  :\n%S\n\n", cmd->outfiles);
	fd_printf(fd, "    * args      :\n%S\n\n", cmd->args);
}

void	fd_debug_token(int fd, t_token *tk)
{
	if (!tk)
		return (utl_putchar_fd(fd, '\n'));
	if (tk->string)
		fd_printf(fd, "	- str	= %s\n", tk->string);
	fd_printf(fd, "	- adress	= 0x%X\n", tk);
	fd_printf(fd, "	- p_adress	= 0x%X\n", tk->prev);
	fd_printf(fd, "	- n_adress	= %X\n", tk->next);
	fd_printf(fd, "	- len		= %i\n", tk->len);
	fd_printf(fd, "	- type		= %i\n", tk->type);
	fd_printf(fd, "	- env str	=\n%S\n\n", tk->env_str);
}
