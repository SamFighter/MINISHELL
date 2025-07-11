/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:11:03 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/02 08:57:58 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	get_tk_start(t_token **token, int pos)
{
	t_token	*tk;
	char	*tmp;

	tk = *token;
	if (pos > 0)
	{
		tmp = str_duppart(tk->string, 0, pos);
		tk->string = str_rep(tk->string, tmp);
		free(tmp);
	}
	*token = tk;
}
