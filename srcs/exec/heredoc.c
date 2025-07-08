/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:43:52 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/27 15:01:49 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	error_heredoc(char *str)
{
	ft_printf("warning: here-document delimited by end-of-file");
	ft_printf("(wanted '%s')\n", str);
}

static int	read_prompt(int fd, char *str)
{
	char	*prompt;

	while (1)
	{
		prompt = readline("> ");
		if (!prompt)
		{
			error_heredoc(str);
			return (-1);
		}
		if (!str_strcmp(str, prompt))
		{
			free(prompt);
			break ;
		}
		write(fd, prompt, str_len(prompt));
		write(fd, "\n", 1);
		free(prompt);
	}
	close(fd);
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
	tmp = cnv_itoa(i++);
	if (!tmp)
		return (result);
	tmp = str_join(result, "_");
	free(result);
	result = str_join(tmp, tmp);
	free(tmp);
	return (result);
}

int	here_doc(char *eof)
{
	int		fd;
	char	*tmp_name;

	tmp_name = get_tmp_name();
	if (!tmp_name)
		return (-1);
	fd = open(tmp_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (free(tmp_name), -1);
	if (read_prompt(fd, eof))
		return (unlink(tmp_name), free(tmp_name), -1);
	fd = open(tmp_name, O_RDONLY);
	if (fd > 0)
		unlink(tmp_name);
	return (free(tmp_name), fd);
}
