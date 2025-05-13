/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:31:39 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/13 19:43:21 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	export_no_args(t_controller *cont)
{
	char	**env;
	char 	*cut;
	int		i;
	int		y;

	env = cont->env;
	if (!env)
		return (1);
	y = 0;
	while (env[y])
	{
		cut = env_cut(env[y]);
		i = 0;
		ft_printf("declare -x ");
		while (env[y][i] != '=')
			ft_printf("%c", env[y][i++]);
		ft_printf("=\"%s\"\n", cut);
		y++;
	}
	return (0);
}

static int	syntax_export(char *str)
{
	int i;

	i = 0;
	if (!str[0] || (str[0] != '_' && !ctn_isalpha(str[0])))
		return (1);
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '_' && !ctn_isalnum(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_alr_env(char **env, char *str)
{
	int i;
	int	j;

	if (!env)
		return (-1);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	j = 0 ;
	while (env[j])
	{
		if (!str_ncmp(env[j], str, i) && (env[j][i] == '\0' || env[j][i] == '='))
			return (j);
		j++;
	}
	return (-1);
}

char	*exportation(char *str, t_controller *cont)
{
	int	pos;

	if (!cont->env)
		return (NULL);
	pos = check_alr_env(cont->env, str);
	if (pos >= 0)
	{
		free(cont->env[pos]);
		cont->env[pos] = NULL;
		cont->env[pos] = str_dup(str);
		return (cont->env[pos]);
	}
	else if (pos < 0)
		cont->env = str_arrdup_nset(cont->env, str);
	return (cont->env[utl_dbl_arrlen(cont->env)]);
}

int	ft_export(t_controller *cont, char **args)
{
	int	j;

	j = 1;
	if (!args || args[j])
	{
		if (cont->env && !export_no_args(cont))
			ft_printf("export: invalid identifier\n");
		cont->excode = 0;
		return (cont->excode);
	}
	while (args[j])
	{
		if(!syntax_export(args[j]))
		{
			ft_printf("export: invalid identifier\n");
			cont->excode = 1;
		}
		else if (!exportation(args[j], cont))
			return (cont->excode);
		j++;
	}
	return (cont->excode);
}
