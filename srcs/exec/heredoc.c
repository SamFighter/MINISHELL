/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:43:52 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/17 11:11:17 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	error_heredoc(char *str, char *str2)
{
	if (g_sig != SIGINT)
	{
		ft_printf("warning: here-document delimited by end-of-file");
		ft_printf("(wanted '%s')\n", str2);
	}
	if (str)
		free(str);
	if (str2)
		free(str2);
	str = NULL;
	str2 = NULL;
}

static void	free_hd(char *str, char *str2)
{
	if (str)
		free(str);
	if (str2)
		free(str2);
}

static int	read_prompt(int *fd, char *str, int code, char **env)
{
	char	*prompt;
	char	*tmp;

	prompt = NULL;
	tmp = str_dup(str);
	if (code == 1)
		tmp = rem_quote_tk(tmp, 0);
	while (g_sig != SIGINT)
	{
		prompt = readline("> ");
		if (!prompt)
		{
			error_heredoc(prompt, tmp);
			break ;
		}
		if (!str_cmp(prompt, tmp))
		{
			free_hd(prompt, tmp);
			break ;
		}
		expand_str(prompt, env, fd[0], code);
	}
	dup2(fd[1], 0);
	return (0);
}

static char	*get_tmp_name(void)
{
	char		*tmp;
	char		*result;
	static int	i = 0;

	tmp = cnv_itoa(getpid());
	if (!tmp)
		return (NULL);
	result = str_join(".tmp_heredoc_", tmp);
	free(tmp);
	if (!result)
		return (NULL);
	tmp = cnv_itoa(i++);
	if (!tmp)
		return (result);
	free(tmp);
	tmp = str_join(result, ".tmp");
	free(result);
	result = str_join("/tmp/", tmp);
	free(tmp);
	return (result);
}

int	here_doc(char *eof, int code, char **env)
{
	int		fd[2];
	char	*tmp_name;

	tmp_name = get_tmp_name();
	fd[1] = dup(0);
	signal(SIGINT, sig_hd);
	if (!tmp_name)
		return (-1);
	fd[0] = open(tmp_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[0] < 0)
	{
		free(tmp_name);
		return (-1);
	}
	read_prompt(fd, eof, code, env);
	close(fd[0]);
	fd[0] = open(tmp_name, O_RDONLY);
	if (fd[0] > 0)
		unlink(tmp_name);
	free(tmp_name);
	close(fd[1]);
	return (fd[0]);
}
