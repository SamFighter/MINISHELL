/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/27 15:02:41 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/headers/libft.h"
# include "tokenizer.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>
# include <wait.h>
# include <readline/readline.h>
# include <readline/history.h>

//----------------   Prompt   ----------------------------------

# define PROMPT			"-minihell # >"
# define EXCODE_0		"\033[1;92m✔\033[0m"
# define EXCODE_1		"\033[1;31m▲\033[0m"
# define EXCODE_2		"\033[1;93m◮\033[0m"
# define EXCODE_3		"\033[1;95m●\033[0m"	//<= 128
# define EXCODE_4		"\033[1;94m◑\033[0m"	//> 128
# define GST_USER		"\033[1;93mguest\033[0m"
# define ROT_USER		"\033[1;95mroot\033[0m"

//----------------   structs   ---------------------------------

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
	char		**env;
	int			pip[2];
	t_cmdlist	cmdlist;
}	t_controller;

//--------------------------------------------------------------

extern int	g_sig;

//--------------------------------------------------------------
//----------------   FUNCTIONS   -------------------------------
//--------------------------------------------------------------

//----------------   Main   ------------------------------------

int		tokenizer(char *str, t_controller *cont);
char	*prompt_controller(int excode, char **env);
void	cmdlist_reset(t_cmdlist *cmdlist);
void	closing(t_controller *cont);
void	controller_exec(t_controller *controller);

//----------------   Init & Free   -----------------------------

void	initializer(t_controller *controller, char **env);
t_cmd	*init_cmd(void);
void	controller_free(t_controller *cont);
void	cmdlist_free(t_cmdlist *cmdlist);
void	cmd_free(t_cmd	*cmd);
void	tk_free(t_token *tk);

//----------------   Signals   ---------------------------------

void	sig_int(int sig);
// void	sig_segv(int sig);
void	sig_abrt(int sig);

//------------------   Execs   ---------------------------------

bool	is_builtin(t_cmd *cmd);
int		dup_env(t_controller *cont, char **envp);
int		make_env(t_controller *cont);
int		ft_cd(char **args, t_controller *cont);
int		ft_echo(char **args);
int		ft_export(t_controller *cont, char **args);
int		ft_env(t_controller *cont);
int		ft_pwd(void);
int 	ft_unset(char **str, t_controller *cont);
int		check_path(char *path, char *cmd);
char	*search_envp(char *str, char **envp);
char	*env_cut(char *str);
char	*exportation(char *str, t_controller *cont);
bool    search_pipe(t_token *tok);
int		exec(t_controller *cont);
bool    search_pipe(t_token *tok);
int		here_doc(char *eof);
void	redir_in_out(t_controller *cont, t_cmd *cmd, int *pip);
int get_infile(t_token *tok, t_cmd *cmd);
int get_outfile(t_token *tok, t_cmd *cmd);
int exec_builtins(int stou, t_controller *cont, char *cmd_name, char **args);
int		prepare_builtin(t_controller *cont, t_cmd *cmd);
int		check_cmd(t_controller *cont);
char    *get_path(char *str_envp, t_cmdlist *cmdlist);
int		len_cmd(t_cmd *cmd);

#endif
