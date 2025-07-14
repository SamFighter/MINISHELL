/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:32:23 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/12 16:03:56 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "minishell.h"

void	print_controller(t_controller *controller);
void	print_cmdlist(t_cmdlist *cmdlist, int title);
void	print_tokens(t_token *tk, int title);
void	print_cmds(t_cmd *cmds, int title);
void	debug_cmd(t_cmd *cmd);
void	debug_token(t_token *tk);

void	fd_print_controller(int fd, t_controller *controller);
void	fd_print_cmdlist(int fd, t_cmdlist *cmdlist, int title);
void	fd_print_tokens(int fd, t_token *tk, int title);
void	fd_print_cmds(int fd, t_cmd *cmds, int title);
void	fd_debug_cmd(int fd, t_cmd *cmd);
void	fd_debug_token(int fd, t_token *tk);

void	log_controller(t_controller *controller, int save);
void	log_tokens(t_token *tk, int save);
void	log_cmds(t_cmd *cmds, int save);

#endif