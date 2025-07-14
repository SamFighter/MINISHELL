/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:48:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/08 18:43:16 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static char	*try_path(char *env_path, int start, int end, char *cmd)
{
	char	*dir;
	char	*tmp;
	char	*full_path;

	if (end - start <= 0)
		return (NULL);
	dir = str_substr(env_path, start, end - start);
	if (!dir)
		return (NULL);
	tmp = str_join(dir, "/");
	free(dir);
	if (!tmp)
		return (NULL);
	full_path = str_join(tmp, cmd);
	free(tmp);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	return (free(full_path), NULL);
}

char	*search_in_path(char *str_envp, char *cmd)
{
	char	*path;
	int		i;
	int		start;

	if (!str_envp || !cmd)
		return (NULL);
	i = 0;
	start = 0;
	while (str_envp[i])
	{
		if (str_envp[i] == ':')
		{
			path = try_path(str_envp, start, i, cmd);
			if (path)
				return (path);
			start = i + 1;
		}
		i++;
	}
	return (try_path(str_envp, start, i, cmd));
}

char	*get_path(char *str_envp, t_cmd *cmd)
{
	if (!cmd || !cmd->str_cmd)
		return (NULL);
	if (cmd->str_cmd[0] == '/' || \
		(cmd->str_cmd[0] == '.' && cmd->str_cmd[1] == '/'))
	{
		if (access(cmd->str_cmd, F_OK) == 0 && access(cmd->str_cmd, X_OK) == 0)
			return (str_dup(cmd->str_cmd));
		return (NULL);
	}
	if (!str_envp)
		return (NULL);
	return (search_in_path(str_envp, cmd->str_cmd));
}

int	process_commands(t_controller *controller)
{
	t_token		*current_tok;
	t_cmd		*current_cmd;

	current_tok = controller->cmdlist.cmds->tokens;
	current_cmd = controller->cmdlist.cmds;
	while (current_tok && current_cmd)
	{
		if ((get_infile(current_tok, current_cmd) == 1 || \
			get_outfile(current_tok, current_cmd) == 1) && g_sig != SIGINT)
		{
			fd_printf(2, "minihell: syntax error");
			fd_printf(2, " near unexpected token `newline'\n");
			return (1);
		}
		while (current_tok && current_tok->type != PIPE)
			current_tok = current_tok->next;
		if (current_tok && current_tok->type == PIPE)
			current_tok = current_tok->next;
		current_cmd = current_cmd->next;
	}
	return (0);
}
