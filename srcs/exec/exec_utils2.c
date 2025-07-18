/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:03 by salabbe           #+#    #+#             */
/*   Updated: 2025/07/17 11:19:46 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_child_status(t_controller *cont, int pid, int status,
	int last_pid)
{
	if (pid == last_pid)
	{
		if (WIFEXITED(status))
			cont->excode = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			cont->excode = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGQUIT)
				ft_printf("Quit (core dumped)\n");
			else if (WTERMSIG(status) == SIGINT)
				ft_printf("\n");
		}
	}
}

void	sig_hd(int sig)
{
	(void) sig;
	g_sig = SIGINT;
	printf("\n");
	close(0);
}

void	expand_str(char *str, char **env, int fd, int code)
{
	int		i;
	int		len;
	char	**str_env;
	char	*s;

	i = 0;
	if (code)
	{
		fd_printf(fd, "%s\n", str);
		return ;
	}
	str_env = NULL;
	str_env = mult_str_env(str_env, str);
	len = str_arrlen((const char **)str_env);
	while (i < len)
	{
		s = get_env(str_env[i], env);
		str = rep_mult_atoa(str, str_env[i++], s);
		free(s);
	}
	fd_printf(fd, "%s\n", str);
	if (str)
		free(str);
	if (str_env)
		utl_super_free((void **)str_env);
}
