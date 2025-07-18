/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/17 11:17:19 by fmontel          ###   ########.fr       */
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

/**
 * @param	char			*string;
 * @param	char			**env_str;
 * @param	int				len;
 * @param	int				type;
 */
typedef struct s_token
{
	char			*string;
	char			**env_str;
	int				len;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

/**
 * @param	t_token			*tokens;
 * @param	int				has_cmd;
 * @param	int				nb_tokens;
 * @param	char			*str_cmd;
 * @param	char			**args;
 * @param	char			**infiles;
 * @param	char			**outfiles;
 * @param	int				fd_inf;
 * @param	int				fd_out;
 */
typedef struct s_cmd
{
	t_token			*tokens;
	int				has_cmd;
	int				nb_tokens;
	char			*str_cmd;
	char			**args;
	char			**infiles;
	char			**outfiles;
	int				fd_inf;
	int				fd_out;
	pid_t			pid;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

/**
 * @param	t_token	*tokens;
 * @param	t_cmd	*cmds;
 * @param	int		invalid;
 */
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

void		cmd_toarr(t_cmdlist **cmdlist, char **env, int excode);
void		tk_remnull(t_cmd **cmds);
int			check_invalid(t_cmd	**cmds);

//----------------   Init Tokens   -----------------------------

t_token		*tk_init(void);
t_token		*tk_initnext(t_token *tk, char c);
t_token		*tk_dup(t_cmd **cmd, t_token *original_tk, int type);
void		tk_end(t_token *tk);
void		tk_fuse(t_token **token, t_token **tk_next);
t_token		*tk_inject(t_token **open, t_token*close, t_token *inject);
t_token		*tk_addnode(t_token *tk, t_token **tk_all);

//----------------   Go To Start   -----------------------------

void		tk_tostart(t_token **tk);
void		tk_tolast(t_token **tk);
void		cmd_tostart(t_cmd **cmd);

//-------------   Literals & Symbols   -------------------------

int			ctn_quote(char *str, int pos, int literal);
int			ctn_quote_both(char *str, int pos, int in_quote);
int			ctn_quotes(int literal, int pos, char c, char prev_c);
int			ctn_quotec(int literal, int pos, char c, char prev_c);
int			reset_quote(int quote, char c, char prev_c);
int			ctn_smbl(char *str, int pos);
int			ctn_smbl_tk(char *str);
char		*rem_quote_tk(char *tk, int type);

//--------------   Set Token Types   ---------------------------

int			tk_type_infile(t_cmd **cmds, t_token **token);
int			tk_type_outfile(t_cmd **cmds, t_token **token);
int			tk_type_cmd(t_cmd **cmds, t_token **token);
void		tk_type_arg(t_cmd **cmds, t_token **token);
void		tk_type_pipe(t_cmd **cmds, t_token **token);

//----------------   Expande Env   -----------------------------

char		*str_env(char *str);
char		**mult_str_env(char **env, char *str);
void		expander(t_cmd *cmds, char **env, int excode);
void		get_tk_start(t_token **token, int pos);

//--------------   Remove Literals   ---------------------------

void		rem_quote_str(t_cmd *cmds);

#endif
