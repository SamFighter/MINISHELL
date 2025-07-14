/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:19:52 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/10 15:07:40 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_token	*tk_expand(t_token *tk, char **env);
t_token	*expand_env(t_token *tk, char *env, char *str);
t_token	*cut_env(t_token *tk, char *env, char *str, int pos);
t_token	*clean_tk(t_token *tk, t_token *tk_next, char *env, int i);

/**
 * Expand enviroment variables in tokens to their values if they exist
 */
void	expander(t_cmd *cmds, char **env, int excode)
{
	t_token	*tk;
	char	*excode_toa;

	excode_toa = cnv_itoa(excode % 256);
	while (cmds)
	{
		tk = cmds->tokens;
		while (tk)
		{
			if (str_nstr(tk->string, "$?"))
				tk->string = rep_mult_atoa(tk->string, "$?", excode_toa);
			else
				tk = tk_expand(tk, env);
			if (!tk->next)
				break ;
			tk = tk->next;
		}
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
	free(excode_toa);
	cmd_tostart(&cmds);
}

t_token	*tk_expand(t_token *tk, char **env)
{
	int		i;
	int		len;
	char	*tmp;
	char	*str;

	i = 0;
	len = str_arrlen((const char **)tk->env_str);
	while (i < len && tk->env_str)
	{
		tmp = search_envp(tk->env_str[i], env);
		str = env_cut(tmp);
		if (str && (tk->type != INPUT || (tk->type == INPUT
					&& tk->prev && tk->prev->type != HEREDOC)))
			tk = expand_env(tk, tk->env_str[i], str);
		else if ((tk->type != INPUT))
			tk->string = rep_mult_atoa(tk->string, tk->env_str[i], NULL);
		free(tmp);
		free(str);
		i++;
		if (!tk->next && !str_nstr(tk->string, tk->env_str[i]))
			return (tk);
	}
	return (tk);
}

t_token	*expand_env(t_token *tk, char *env, char *str)
{
	int		i;
	int		len;
	int		quote;

	i = -1;
	len = str_len(tk->string);
	quote = 0;
	while (++i < len)
	{
		quote = ctn_quote_both(tk->string, i, quote);
		if (tk->string[i] == '$' && str_nlstr(tk->string, env, i) && quote == 1)
		{
			tk->string = rep_latoa(tk->string, env, str, i);
			i += str_len(str);
		}
		else if (tk->string[i] == '$'
			&& str_nlstr(tk->string, env, i) && quote == 0)
			return (cut_env(tk, env, str, i));
	}
	return (tk);
}

t_token	*cut_env(t_token *tk, char *env, char *str, int pos)
{
	char	**sarr;
	t_token	*new;
	int		i;

	i = 0;
	sarr = str_atoarr_ws(str);
	new = NULL;
	if (sarr)
		new = tk_init();
	while (sarr[i])
	{
		new->string = str_dup(sarr[i]);
		new->type = tk->type;
		new->env_str = str_arrdup(tk->env_str);
		i++;
		if (sarr[i])
			new = tk_initnext(new, 1);
	}
	utl_super_free((void **)sarr);
	return (clean_tk(tk, tk_inject(&tk, tk->next, new), env, pos));
}

t_token	*clean_tk(t_token *tk, t_token *tk_next, char *env, int pos)
{
	int		len;
	char	*prev;
	char	*new;

	len = str_len(tk->string);
	prev = str_duppart(tk->string, 0, pos);
	new = str_duppart(tk->string, pos + str_len(env), len - pos - str_len(env));
	get_tk_start(&tk, pos);
	if (tk->next)
	{
		tk->string = str_rep(tk->string, prev);
		if (tk_next == tk->next)
			tk_next = tk;
		tk_fuse(&tk, &tk->next);
	}
	if (new)
		tk_next->string = str_rejoin(tk_next->string, new);
	tk = tk_next;
	free(prev);
	free(new);
	return (tk);
}
