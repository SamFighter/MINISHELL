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

#include "../../../headers/minishell.h"
#include "../../../libft/headers/libft.h"

/**
 * Return a string (char *) using the user environment-variable and exit-code
 */
char	*promt_controller(t_controller *cont)
{
	char	*str;
	char	*tmp;

	(void)cont;
	tmp = getenv("USER");
	if (!tmp)
		tmp = GST_USER;
	if (ft_strncmp(tmp, "root", 4) == 0)
		tmp = ROT_USER;
	str = ft_strjoin(tmp, PROMPT);
	if (cont->excode == 0)
		tmp = mult_ctoa(str, '#', EXCODE_0);
	else if (cont->excode == 1)
		tmp = mult_ctoa(str, '#', EXCODE_1);
	else if (cont->excode == 2)
		tmp = mult_ctoa(str, '#', EXCODE_2);
	else if (cont->excode == 3)
	//else if (cont->excode <= 128)
		tmp = mult_ctoa(str, '#', EXCODE_3);
	else
		tmp = mult_ctoa(str, '#', EXCODE_4);
	free(str);
	return (tmp);
}
