/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:07:09 by salabbe           #+#    #+#             */
/*   Updated: 2025/05/19 11:23:49 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int check_syntax(char *str)
{
    int i;

    if (!str || (!ctn_isalpha(str[0]) && str[0] != '_'))
        return (1);
    i = 1;
    while (str[i])
    {
        if (!ctn_isalnum(str[i]) && str[i] != '_')
            return (1);
        i++;
    }
    return (0);
}

static int check_alr_env(char **env, char *str)
{
    int i;
    int j;
    int len;

    if (!env || !str)
        return (-1);
    len = str_len(str);
    j = 0;
    while (env[j])
    {
        i = 0;
        while (env[j][i] && env[j][i] != '=' && i < len)
            i++;
        if (i == len && !str_ncmp(env[j], str, len))
            return (j);
        j++;
    }
    return (-1);
}

static void remove_env_var(char **env, int pos)
{
    int i;

    free(env[pos]);
    i = pos;
    while (env[i])
    {
        env[i] = env[i + 1];
        i++;
    }
}

static bool unset(t_controller *cont, char *str)
{
    int pos;

    if (!str)
        return (false);
    if (check_syntax(str))
    {
        ft_printf("unset : invalid indentifier\n");
        return (true);
    }
    pos = check_alr_env(cont->env, str);
    if (pos == -1)
        return (false);
	else
		remove_env_var(cont->env, pos);
    return (false);
}

/**
 * @brief Same functionnality as the unset Built-in
 * 
 * @param str 
 * @param cont 
 * @return int 
 */
int ft_unset(char **str, t_controller *cont)
{
    int j;

    j = 0;
    while (str[j])
    {
        if (unset(cont, str[j]))
            cont->excode = 1;
        j++;
    }
    return(cont->excode);
}
