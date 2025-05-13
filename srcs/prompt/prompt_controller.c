/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:50:33 by fmontel           #+#    #+#             */
/*   Updated: 2025/04/16 19:17:06 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * Return a string (char *) using the user environment-variable and exit-code
 */
char	*prompt_controller(int excode, char **env)
{
	char	*str;
	char	*tmp;

	(void)env;
	tmp = strdup(getenv("USER")); // search_envp("USER", env);
	if (!tmp)
		tmp = GST_USER;
	if (str_ncmp(tmp, "root", 4) == 0)
		tmp = ROT_USER;
	str = str_join(tmp, PROMPT);
	if (excode == 0)
		str = rep_mult_ctoa(str, '#', EXCODE_0);
	else if (excode == 1)
		str = rep_mult_ctoa(str, '#', EXCODE_1);
	else if (excode == 2)
		str = rep_mult_ctoa(str, '#', EXCODE_2);
	else if (excode <= 128)
		str = rep_mult_ctoa(str, '#', EXCODE_3);
	else
		str = rep_mult_ctoa(str, '#', EXCODE_4);
	free(tmp);
	return (str);
}
