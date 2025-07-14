/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_colorstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:17:43 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/13 14:06:10 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*rep_colorstr2(char *str);

/**
 * Replace all the visual.h color codes in a string
 */
char	*rep_colorstr(char *str)
{
	str = rep_mult_atoa(str, ___W, ___WHI);
	str = rep_mult_atoa(str, ___R, ___RED);
	str = rep_mult_atoa(str, ___Y, ___YEL);
	str = rep_mult_atoa(str, ___G, ___GRE);
	str = rep_mult_atoa(str, ___C, ___CYA);
	str = rep_mult_atoa(str, ___B, ___BLU);
	str = rep_mult_atoa(str, ___P, ___PUR);
	str = rep_mult_atoa(str, ___D, ___DAR);
	str = rep_mult_atoa(str, L__R, L__RED);
	str = rep_mult_atoa(str, L__Y, L__YEL);
	str = rep_mult_atoa(str, L__G, L__GRE);
	str = rep_mult_atoa(str, L__C, L__CYA);
	str = rep_mult_atoa(str, L__B, L__BLU);
	str = rep_mult_atoa(str, L__P, L__PUR);
	str = rep_mult_atoa(str, L__D, L__DAR);
	str = rep_colorstr2(str);
	return (str);
}

char	*rep_colorstr2(char *str)
{
	str = rep_mult_atoa(str, _B_W, _B_WHI);
	str = rep_mult_atoa(str, _B_R, _B_RED);
	str = rep_mult_atoa(str, _B_Y, _B_YEL);
	str = rep_mult_atoa(str, _B_G, _B_GRE);
	str = rep_mult_atoa(str, _B_C, _B_CYA);
	str = rep_mult_atoa(str, _B_B, _B_BLU);
	str = rep_mult_atoa(str, _B_P, _B_PUR);
	str = rep_mult_atoa(str, _B_D, _B_DAR);
	str = rep_mult_atoa(str, LB_R, LB_RED);
	str = rep_mult_atoa(str, LB_Y, LB_YEL);
	str = rep_mult_atoa(str, LB_G, LB_GRE);
	str = rep_mult_atoa(str, LB_C, LB_CYA);
	str = rep_mult_atoa(str, LB_B, LB_BLU);
	str = rep_mult_atoa(str, LB_P, LB_PUR);
	str = rep_mult_atoa(str, LB_D, LB_DAR);
	return (str);
}
