/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:26:59 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 17:13:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/debug.h"

/**
 * Print the whole content of a token (t_token *) in the console
 * - If 'title' is set to 1, print the title
 */
void	print_tokens(t_token *tk, int title)
{
	int	i;

	i = 0;
	if (!tk)
		return (utl_putchar('\n'));
	if (title == 1)
	{
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		ft_printf("    -------- DEBUG PRINT --------\n\n");
		ft_printf("	   ---- TOKEN ----\n\n");
	}
	while (tk->next)
	{
		ft_printf("    * token nb %i:\n", i++);
		debug_token(tk);
		tk = tk->next;
	}
	if (tk)
	{
		ft_printf("    * token nb %i:\n", i++);
		debug_token(tk);
	}
	if (title == 1)
		ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
	ft_printf("\n");
}

/**
 * @brief Print the whole content of a token (t_token *) in the 
 * file-descriptor 'fd'
 * 
 * - If 'title' is set to 1, print the title
 */
void	fd_print_tokens(int fd, t_token *tk, int title)
{
	int	i;

	i = 0;
	if (!tk)
		return (utl_putchar_fd(fd, '\n'));
	if (title == 1)
	{
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		fd_printf(fd, "    -------- DEBUG PRINT --------\n\n");
		fd_printf(fd, "	   ---- TOKEN ----\n\n");
	}
	while (tk->next)
	{
		fd_printf(fd, "    * token nb %i:\n", i++);
		fd_debug_token(fd, tk);
		tk = tk->next;
	}
	if (tk)
	{
		fd_printf(fd, "    * token nb %i:\n", i++);
		fd_debug_token(fd, tk);
	}
	if (title == 1)
		fd_printf(fd, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
	fd_printf(fd, "\n");
}

/**
 * @brief Print the whole content of a token (t_token *) in the
 * console and then save it into a log file
 */
void	log_tokens(t_token *tk, int save)
{
	int	fd;

	if (!tk)
	{
		ft_printf("	\033[1;93mNo Token list to print, aborted\033[0m\n\n");
		return ;
	}
	print_tokens(tk, 1);
	if (save)
	{
		fd = open("tokens.log", O_CREAT | O_TRUNC | O_RDWR, 0777);
		if (fd == -1)
		{
			ft_printf("	\033[1;31mToken Log could not be saved\033[0m\n\n");
			return ;
		}
		fd_print_tokens(fd, tk, 1);
		ft_printf("	\033[1;92mTokens Log saved sucessfully\033[0m\n\n");
	}
}
