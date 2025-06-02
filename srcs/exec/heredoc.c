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

static void error_heredoc(char *str)
{
    ft_printf("warning: here-document delimited by end-of-file");
    ft_printf("(wanted '%s')\n", str);
}
static int  read_prompt(int fd, char *str)
{
    char    *prompt;

    while (1)
    {
        prompt = NULL;
        prompt = readline("> ");
        if (!prompt)
            error_heredoc(str);
        if (!str_ncmp(str, prompt, INT_MAX))
            break ;
        write(fd, prompt, str_len(prompt));
        write(fd, "\n", 1);
        free(prompt);
    }
    free(prompt);
    close(fd);
    return (0);
}

int here_doc(char *eof, t_controller *cont)
{
    int fd;

    fd = open(".tmp_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
        return (-1);
    if (!read_prompt(fd, eof))
    {
        unlink(".tmp_heredoc");
        return (-1);
    }
    fd = open(".tmp_heredoc", O_RDONLY);
    if (fd > 0)
        unlink(".tmp_heredoc");
    return (fd);
}