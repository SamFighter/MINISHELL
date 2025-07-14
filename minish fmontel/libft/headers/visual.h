/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:08:06 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/08 08:33:31 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

//----------------   Color Codes   --------------------------------

# define ___WHI				"\033[0m"
# define ___RED				"\033[0;31m"
# define ___YEL				"\033[0;33m"
# define ___GRE				"\033[0;32m"
# define ___CYA				"\033[0;36m"
# define ___BLU				"\033[0;34m"
# define ___PUR				"\033[0;35m"
# define ___DAR				"\033[0;30m"

# define L__RED				"\033[0;91m"
# define L__YEL				"\033[0;93m"
# define L__GRE				"\033[0;92m"
# define L__CYA				"\033[0;96m"
# define L__BLU				"\033[0;94m"
# define L__PUR				"\033[0;95m"
# define L__DAR				"\033[0;90m"

# define _B_WHI				"\033[1;37m"
# define _B_RED				"\033[1;31m"
# define _B_YEL				"\033[1;33m"
# define _B_GRE				"\033[1;32m"
# define _B_CYA				"\033[1;36m"
# define _B_BLU				"\033[1;34m"
# define _B_PUR				"\033[1;35m"
# define _B_DAR				"\033[1;30m"

# define LB_RED				"\033[1;91m"
# define LB_YEL				"\033[1;93m"
# define LB_GRE				"\033[1;92m"
# define LB_CYA				"\033[1;96m"
# define LB_BLU				"\033[1;94m"
# define LB_PUR				"\033[1;95m"
# define LB_DAR				"\033[1;90m"

//----------------   Color Strings   -------------------------------

# define ___W				"#___w"
# define ___R				"#___r"
# define ___Y				"#___y"
# define ___G				"#___g"
# define ___C				"#___c"
# define ___B				"#___b"
# define ___P				"#___p"
# define ___D				"#___d"

# define L__R				"#l__r"
# define L__Y				"#l__y"
# define L__G				"#l__g"
# define L__C				"#l__c"
# define L__B				"#l__b"
# define L__P				"#l__p"
# define L__D				"#l__d"

# define _B_W				"#_b_w"
# define _B_R				"#_b_r"
# define _B_Y				"#_b_y"
# define _B_G				"#_b_g"
# define _B_C				"#_b_c"
# define _B_B				"#_b_b"
# define _B_P				"#_b_p"
# define _B_D				"#_b_d"

# define LB_R				"#lb_r"
# define LB_Y				"#lb_y"
# define LB_G				"#lb_g"
# define LB_C				"#lb_c"
# define LB_B				"#lb_b"
# define LB_P				"#lb_p"
# define LB_D				"#lb_d"

//------------------------------------------------------------------

char	*rep_colorstr(char *str);

#endif