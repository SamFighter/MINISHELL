# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 10:51:03 by salabbe           #+#    #+#              #
#    Updated: 2025/07/15 15:27:54 by fmontel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	get_next_line.c 				\
					print_f/ft_printf.c 			\
					print_f/ft_sideprintf.c 		\
					print_f/fd_printf.c 			\
					print_f/fd_sideprintf.c 		\
					print_f/utl_printf.c 			\
					visual/rep_colorstr.c			\
					func_contain/ctn_chckchar.c		\
					func_contain/ctn_isalnum.c		\
					func_contain/ctn_isalpha.c		\
					func_contain/ctn_isascii.c		\
					func_contain/ctn_ischar.c		\
					func_contain/ctn_isdigit.c		\
					func_contain/ctn_isprint.c		\
					func_contain/ctn_iswhitespace.c	\
					func_contain/ctn_strchr.c		\
					func_contain/ctn_strrchr.c		\
					func_convert/cnv_atoi.c			\
					func_convert/cnv_str.c			\
					func_convert/cnv_sttoa.c		\
					func_convert/cnv_itoa.c			\
					func_memory/mem_bzero.c			\
					func_memory/mem_calloc.c		\
					func_memory/mem_chr.c			\
					func_memory/mem_cmp.c			\
					func_memory/mem_cpy.c			\
					func_memory/mem_move.c			\
					func_memory/mem_set.c			\
					func_replacement/rep_atoa.c		\
					func_replacement/rep_atoi.c		\
					func_replacement/rep_ctoa.c		\
					func_replacement/rep_ctoi.c		\
					func_replacement/rep_ctonull.c	\
					func_replacement/rep_ptonull.c	\
					func_replacement/rep_tolower.c	\
					func_replacement/rep_toupper.c	\
					func_string/str_arrdup.c		\
					func_string/str_arrrep.c		\
					func_string/str_atoarr.c		\
					func_string/str_cat.c			\
					func_string/str_cmp.c			\
					func_string/str_cpy.c			\
					func_string/str_dup.c			\
					func_string/str_duppart.c		\
					func_string/str_iteri.c			\
					func_string/str_join.c			\
					func_string/str_llstr.c			\
					func_string/str_len.c			\
					func_string/str_mapi.c			\
					func_string/str_rep.c			\
					func_string/str_rarrdup.c		\
					func_string/str_rarrrep.c		\
					func_string/str_split.c			\
					func_string/str_str.c			\
					func_string/str_substr.c		\
					func_string/str_trim.c			\
					func_string/str_arrjoin.c		\
					func_utility/utl_dbl_arrlen.c	\
					func_utility/utl_getlen_line.c	\
					func_utility/utl_int_len.c		\
					func_utility/utl_putchar.c		\
					func_utility/utl_putarrstr.c	\
					func_utility/utl_putendl.c		\
					func_utility/utl_putnbr.c		\
					func_utility/utl_putstr.c		\
					func_utility/utl_super_free.c	\

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d)

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -g
CPPFLAGS		:=	-MP -MMD -Ilibft/debug.h		\
					-Ilibft/headers/func_cnv.h		\
					-Ilibft/headers/func_ctn.h		\
					-Ilibft/headers/func_mem.h		\
					-Ilibft/headers/func_rep.h		\
					-Ilibft/headers/func_str.h		\
					-Ilibft/headers/func_utl.h		\
					-Ilibft/headers/ft_printf.h		\
					-Ilibft/headers/get_next_line.h	\
					-Ilibft/headers/libft.h			\

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(M_OBJS)
	ar -rc $(NAME) $(M_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

add-ons: $(AO_OBJS)
	ar -rc $(NAME) $(AO_OBJS)

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;92m
YELLOW			:= \033[0;93m
BLUE			:= \033[0;94m
CYAN			:= \033[0;96m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "		 _     _ _      __ _		"
	@echo "		| |   (_) |__  / _| |_		"
	@echo "		| |   | |  _ \| |_| __|		"
	@echo "		| |___| | |_) |  _| |_ 		"
	@echo "		|_____|_|____/|_|  \__|		"
	@echo "		      by Salabbe            "
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
