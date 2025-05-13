/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:19:52 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 14:10:06 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	expander(t_cmd *cmds, char **env)
{
	t_token	*tk;

	while (cmds)
	{
		tk = cmds->tokens;
		while (tk)
		{
			tk_expand(tk, env);
			if (!tk->next)
				break ;
			tk = tk->next;
		}
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
	cmd_tostart(&cmds);
}

void	tk_expand(t_token *tk, char **env)
{
	int		i;
	int		len;
	char	*tmp;

	(void)env;
	i = 0;
	len = str_arrlen((const char **)tk->env_str);
	while (i < len)
	{
		tmp = NULL; // search_envp(tk->env_str[env_len], env);
		tk->string = rep_mult_atoa(tk->string, tk->env_str[i], tmp);
		free(tmp);
		i++;
	}
}
