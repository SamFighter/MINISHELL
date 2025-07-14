/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rep.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/07/08 18:05:06 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_REP_H
# define FUNC_REP_H

char		*rep_ctoa(char *str, char c, char *append);
char		*rep_atoa(char *str, char *rep, char *apn);
char		*rep_mult_ctoa(char *str, char c, char *append);
char		*rep_mult_atoa(char *str, char *rep, char *apn);
char		*rep_atoi(char *str, char *rep, int apn);
char		*rep_mult_atoi(char *str, char *rep, int apn);
char		*rep_ctoi(char *str, char c, int apn);
char		*rep_mult_ctoi(char *str, char c, int apn);
char		*rep_ctonull(char *str, char c);
char		*rep_mult_ctonull(char *str, char c);
char		*rep_ptonull(char *str, int pos);
int			rep_toupper(int c);
int			rep_tolower(int c);
char		*rep_latoa(char *str, char *rep, char *apn, int start);

#endif