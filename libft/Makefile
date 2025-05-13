# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 10:51:03 by salabbe           #+#    #+#              #
#    Updated: 2025/04/29 19:28:52 by salabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	ft_atoi.c 					\
					ft_bzero.c 					\
					ft_calloc.c 				\
					ft_isalnum.c 				\
					ft_isalpha.c 				\
					ft_isascii.c 				\
					ft_isdigit.c 				\
					ft_isprint.c 				\
					ft_iswhitespace.c 			\
					ft_itoa.c 					\
					ft_memchr.c 				\
					ft_memcmp.c 				\
					ft_memcpy.c 				\
					ft_memmove.c 				\
					ft_memset.c 				\
					ft_split.c 					\
					ft_strchr.c 				\
					ft_strdup.c 				\
					ft_striteri.c 				\
					ft_strjoin.c 				\
					ft_strlcat.c 				\
					ft_strlcpy.c 				\
					ft_strlen.c 				\
					ft_strmapi.c 				\
					ft_strncmp.c 				\
					ft_strstr.c 				\
					ft_strrchr.c 				\
					ft_strtrim.c 				\
					ft_substr.c 				\
					ft_tolower.c 				\
					ft_toupper.c 				\
					ft_putendl_fd.c 			\
					checkchar.c 				\
					super_free.c 				\
					get_next_line.c				\
					strarr_dup.c 				\
					sf_tablen.c 				\
					ft_putchar.c 				\
					ft_putnbr.c 				\
					ft_putstr.c 				\
					len_int.c					\
					print_f/ft_printf.c 		\
					print_f/ft_sideprintf.c 	\
					ctoa.c						\

BONUS			:= 	ft_lstnew_bonus.c 			\
					ft_lstsize_bonus.c 			\
					ft_lstadd_front_bonus.c 	\
					ft_lstlast_bonus.c 			\
					ft_lstadd_back_bonus.c 		\
					ft_lstdelone_bonus.c 		\
					ft_lstclear_bonus.c 		\
					ft_lstiter_bonus.c 			\
					ft_lstmap_bonus.c

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d)

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -Ofast
CPPFLAGS		:=	-MP -MMD -Iheaders/minishell.h	\
					-Iheaders/tokenizer.h			\
					-Ilibft/headers/ft_printf.h		\
					-Ilibft/headers/libft.h			\
					-Ilibft/headers/get_next_line.h	\

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

bonus: $(B_OBJS)
	ar -rc $(NAME) $(B_OBJS)

add-ons: $(AO_OBJS)
	ar -rc $(NAME) $(AO_OBJS)

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
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