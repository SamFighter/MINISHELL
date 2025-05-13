/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 15:57:10 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/headers/libft.h"
# include "tokenizer.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <wait.h>

# define PROMPT			"-minihell # >"
# define EXCODE_0		"\033[1;32m✔\033[0m"
# define EXCODE_1		"\033[1;31m▲\033[0m"
# define EXCODE_2		"\033[1;33m◮\033[0m"
# define EXCODE_3		"\033[1;35m●\033[0m"	//<= 128
# define EXCODE_4		"\033[1;94m◑\033[0m"	//> 128
# define GST_USER		"\033[1;33mguest\033[0m"
# define ROT_USER		"\033[1;95mroot\033[0m"

/**
 * @param char			*pwd;
 * @param char			*old_pwd;
 * @param int			excode;
 * @param t_cmdlist		cmdlist;
 * @param char			**env;
 */
typedef struct s_controller
{
	char		*pwd;
	char		*old_pwd;
	int			excode;
	t_cmdlist	cmdlist;
	char		**env;
}	t_controller;

char	*promt_controller(t_controller *cont);
void	init_cont(t_controller *controller);
t_cmd	*init_cmd(void);
void	reset_cmdlist(t_cmdlist *cmdlist);
char	*strenv(char *str);
char	**mult_strenv(char **env, char *str);
void	free_cmdlist(t_cmdlist *cmdlist);
void	free_tokens(t_token *tk);
void	free_cmd(t_cmd	*cmd);
int		dup_env(t_controller *cont, char **envp);
char	*search_envp(char *str, char **envp);
int		make_env(t_controller *cont);
char	*env_cut(char *str);
char	*exportation(char *str, t_controller *cont);
int		ft_cd(char *path, t_controller *cont);
int		ft_echo(char **args);
bool	is_builtin(t_cmd *cmd);
void 	exec_cmd(t_controller *cont);
int		check_path(char *path, char *cmd);

#endif