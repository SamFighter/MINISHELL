/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:14:02 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# define CMD		10
# define ARG		2
# define LIT_STR	3
# define LIT_CHR	4
# define INPUT		5
# define OUTPUT		6
# define PIPE		9
# define IN			-1
# define OUT		-2
# define HEREDOC	-3
# define APPEND		-4

//----------------   structs   ---------------------------------

typedef struct s_token
{
	char			*string;
	char			**env_str;
	int				len;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	t_token			*tokens;
	int				has_cmd;
	int				nb_tokens;
	char			*str_cmd;
	char			**args;
	char			**infiles;
	char			**outfiles;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmdlist
{
	t_token	*tokens;
	t_cmd	*cmds;
	int		invalid;
}	t_cmdlist;

//--------------------------------------------------------------

//--------------------------------------------------------------
//----------------   FUNCTIONS   -------------------------------
//--------------------------------------------------------------

//----------------   Main   ------------------------------------

void		create_tokens(char *str, t_cmdlist *cmdlist);
void		getlen_token(char *str, t_cmdlist *cmdlist);
void		set_type_token(t_cmdlist *cmdlist);
void		cmd_toarr(t_cmdlist **cmdlist, char **env);
void		cmd_toarr2(t_cmdlist **cmdlist, char **env);
void		cmd_toarr3(t_cmdlist **cmdlist);

//----------------   Init Tokens   -----------------------------

t_token		*tk_init(void);
t_token		*tk_initnext(t_token *tk, char c);
t_token		*tk_dup(t_cmd **cmd, t_token *original_tk, int type);
void		tk_end(t_token *tk);

//----------------   Go To Start   -----------------------------

void		tk_tostart(t_token **tk);
void		cmd_tostart(t_cmd **cmd);

//-------------   Literals & Symbols   -------------------------

int			ctn_lit(char *str, int pos, int literal);
int			ctn_lits(int literal, int pos, char c, char prev_c);
int			ctn_litc(int literal, int pos, char c, char prev_c);
int			reset_lit(int literal, char c, char prev_c);
int			ctn_smbl(char *str, int pos);
int			ctn_smbl_tk(char *str);

//--------------   Set Token Types   ---------------------------

int			tk_type_infile(t_cmd **cmds, t_token **token);
int			tk_type_outfile(t_cmd **cmds, t_token **token);
int			tk_type_cmd(t_cmd **cmds, t_token **token);
void		tk_type_arg(t_cmd **cmds, t_token **token);
void		tk_type_pipe(t_cmd **cmds, t_token **token);

//----------------   Expande Env   -----------------------------

char		*str_env(char *str);
char		**mult_str_env(char **env, char *str);
void		expander(t_cmd *cmds, char **env);
void		tk_expand(t_token *tk, char **env);

//--------------   Remove Literals   ---------------------------

void		rem_litstr(t_cmd *cmds);

#endif