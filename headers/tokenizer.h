/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:50:59 by salabbe          ###   ########.fr       */
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

/**
 * @param char		*string;
 * @param int		len;
 * @param int		type;
 */
typedef struct s_token
{
	char			*string;
	int				len;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

/**
 * @param t_token		*tokens 
 * @param int			has_cmd;
 * @param int			nb_tokens;
 * @param char			*str_cmd;
 * @param char			**args;
 * @param char			**infiles;
 * @param char			**outfiles;
 * @param char			**env_str;
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
	char			**env_str;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

/**
 * @param t_token	*tokens;
 * @param t_cmd		*cmds;
 */
typedef struct s_cmdlist
{
	t_token	*tokens;
	t_cmd	*cmds;
}	t_cmdlist;

t_token		*init_token(void);
t_token		*init_nexttoken(t_token *tk, char c);
t_token		*dup_token(t_cmd **cmd, t_token *original_tk, int type);
void		stop_end_token(t_token *tk);
void		find_start_tokens(t_token **tk);
void		find_start_cmds(t_cmd **cmd);

int			tokenizer(char *str, t_cmdlist *cmdlist);
void		getlen_token(char *str, t_cmdlist *cmdlist);
void		create_tokens(char *str, t_cmdlist *cmdlist);
void		set_type_token(t_cmdlist *cmdlist);
void		cmd_to_array(t_cmdlist **cmdlist);
void		cmd_to_array_2(t_cmdlist **cmdlist);
void		cmd_to_array_3(t_cmdlist **cmdlist);

int			check_literals(char *str, int pos, int literal);
int			literal_str(int literal, int pos, char c, char prev_c);
int			literal_chr(int literal, int pos, char c, char prev_c);
int			reset_literal(int literal, char c, char prev_c);
int			check_symbols(char *str, int pos);
int			check_symbols_token(char *str);

int			token_infile(t_cmd **cmds, t_token **token);
int			token_outfile(t_cmd **cmds, t_token **token);
int			token_cmd(t_cmd **cmds, t_token **token);
void		token_arg(t_cmd **cmds, t_token **token);
void		token_pipe(t_cmd **cmds, t_token **token);

#endif