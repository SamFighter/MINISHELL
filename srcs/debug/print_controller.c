/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:21:00 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 16:13:36 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/debug.h"

/**
 * Print the whole content of a controller (t_controller *) in the console
 */
void	print_controller(t_controller *controller)
{
	t_controller	*cont;

	cont = controller;
	ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
	ft_printf("    -------- DEBUG FULL PRINT --------\n\n");
	ft_printf(" * env     :\n%S\n", cont->env);
	ft_printf(" * pwd     : %s\n", cont->pwd);
	ft_printf(" * old_pwd : %s\n", cont->old_pwd);
	ft_printf(" * excode  : %i\n", cont->excode);
	ft_printf("\n	     ---- CMDLIST ----\n\n");
	print_cmdlist(&cont->cmdlist, 0);
	tk_tostart(&controller->cmdlist.tokens);
	tk_tostart(&controller->cmdlist.cmds->tokens);
	ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
}

/**
 * Print the whole content of a cmdlist (t_cmdlist *) in the console
 * - If 'title' is set to 1, print the title
 */
void	print_cmdlist(t_cmdlist *cmdlist, int title)
{
	if (!cmdlist)
		return (utl_putchar('\n'));
	if (title == 1)
	{
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		ft_printf("    -------- DEBUG PRINT --------\n\n");
		ft_printf("	     ---- CMDLIST ----\n\n");
	}
	ft_printf("  * invalid	: %i\n\n", cmdlist->invalid);
	ft_printf("	       --- TOKEN ---\n\n");
	print_tokens(cmdlist->tokens, 0);
	ft_printf("	        --- CMD ---\n\n");
	print_cmds(cmdlist->cmds, 0);
	if (title == 1)
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
}

void	debug_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (utl_putchar('\n'));
	print_tokens(cmd->tokens, 0);
	ft_printf("    * str cmd   : %s\n", cmd->str_cmd);
	ft_printf("    * infiles   :\n%S\n\n", cmd->infiles);
	ft_printf("    * outfiles  :\n%S\n\n", cmd->outfiles);
	ft_printf("    * args      :\n%S\n\n", cmd->args);
}

void	debug_token(t_token *tk)
{
	if (!tk)
		return (utl_putchar('\n'));
	if (tk->string)
		ft_printf("	- str	= %s\n", tk->string);
	ft_printf("	- adress	= 0x%X\n", tk);
	ft_printf("	- p_adress	= 0x%X\n", tk->prev);
	ft_printf("	- n_adress	= %X\n", tk->next);
	ft_printf("	- len		= %i\n", tk->len);
	ft_printf("	- type		= %i\n", tk->type);
	ft_printf("	- env str	=\n%S\n\n", tk->env_str);
}
