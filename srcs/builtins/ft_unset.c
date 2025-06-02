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

static int  check_syntax(char *str)
{
    int i;

    if (str[0] == '_' && !ctn_isalpha(str[0]))
        return (1);
    i = 0;
    while (str[i])
    {
        if (str[i] == '_' && !ctn_isalnum(str[i]))
            return (1);
        i++;
    }
    return (0);
}

static int  check_alr_env(char **env, char *str)
{
    int i;
    int j;

    if (!env || !str)
        return (-1);
    i = 0;
    while (str[i])
        i++;
    j = 0;
    while (env[j])
    {
        if (!str_ncmp(env[j], str, i))
            return (j);
        j++;
    }
    return (-1);
}

static bool unset(t_controller *cont, char *str)
{
    int j;
    int pos;

    if (!str)
        return (false);
    if (!check_syntax(str))
    {
        ft_printf("unset : invalid indentifier\n");
        return (true);
    }
    pos = check_alr_env(cont->env, str);
    if (pos == -1)
        return (false);
    j = 0;
    while (j < pos)
        j++;
    free(cont->env[j]);
    cont->env[j] = NULL;
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