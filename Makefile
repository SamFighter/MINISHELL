# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:41:03 by salabbe           #+#    #+#              #
#    Updated: 2025/05/13 15:51:07 by salabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_NAME		= minishell

# **************************************************************************** #
#								    										   #
#				=======>		INGREDIENTS			<=======		   		   #
#																			   #
# **************************************************************************** #

LIBFT 		= ./libft/libft.a


MANDATORY	= 		srcs/main.c 									\
					srcs/parsing/prompt/free_cmdlist.c 				\
					srcs/parsing/prompt/prompt_controller.c 		\
					srcs/parsing/prompt/reset_cmdlist.c 			\
					srcs/parsing/tokenization/check_literals.c 		\
					srcs/parsing/tokenization/check_symbols.c 		\
					srcs/parsing/tokenization/cmd_to_array.c 		\
					srcs/parsing/tokenization/expander.c 			\
					srcs/parsing/tokenization/init_cmd.c 			\
					srcs/parsing/tokenization/init_token.c 			\
					srcs/parsing/tokenization/strenv.c				\
					srcs/parsing/tokenization/token_set_types.c		\
					srcs/parsing/tokenization/token_utils.c 		\
					srcs/parsing/tokenization/tokenizer.c 			\
					srcs/exec/envp_controller.c						\
					srcs/exec/exec.c								\
					srcs/builtins/ft_export.c						\
					srcs/builtins/ft_cd.c							\
					srcs/builtins/ft_echo.c							\
					srcs/builtins/builtin_utils.c					\

N_OBJS		=	$(MANDATORY:%.c=.build/%.o)
DEPS		=	$(N_OBJS:%.o=%.d)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
CPPFLAGS	=	-MP	-MMD -Iinclude									\
				-Ilibft/libft.a										\
				-Iheaders/minishell.h								\

LDFLAGS		=	-Llibft -lft -lreadline

# **************************************************************************** #
#								    										   #
#			    	=======>		TOOLS			<=======		   		   #
#																			   #
# **************************************************************************** #

MAKEFLAGS	+=	--silent --no-print-directory

# **************************************************************************** #
#								    										   #
#			    	=======>		RECIPES			<=======		   		   #
#																			   #
# **************************************************************************** #

all:	header $(N_NAME)

$(N_NAME): $(LIBFT) $(N_OBJS)
		$(CC) $(CFLAGS) $(N_OBJS) $(LDFLAGS) -o $(N_NAME)
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(_BOLD)OBJS$(_RESET) $(CYAN)in /SO_LONG/.build$(OFF)\n"
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(N_NAME)$(OFF)\n"

$(LIBFT):
		$(MAKE) -C libft

.build/%.o: %.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

-include $(DEPS)

clean:
		$(MAKE) -C libft clean
		@printf "$(PURPLE)$(_BOLD)SUPPRESSION$(OFF)$(_RESET) $(CYAN)/SO_LONG/.build$(OFF)\n"
		rm -rf .build

fclean: clean
		$(MAKE) -C libft fclean
		@printf "$(PURPLE)$(_BOLD)ERRADICATION$(OFF)$(_RESET) $(CYAN)$(N_NAME)$(OFF)\n"
		rm -rf $(N_NAME)

re:
		@printf "$(RED)$(_BOLD)RE-STARTED FROM SCRATCH$(OFF)$(_RESET)\n"
		$(MAKE) fclean
		$(MAKE) all

# **************************************************************************** #
#								    										   #
#			    	=======>		PIMPER			<=======		   		   #
#																			   #
# **************************************************************************** #


OFF			:= \033[0m
RED			:= \033[0;31m
L_RED		:= \033[0;91m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
L_YELLOW	:= \033[0;93m
CYAN		:= \033[0;36m
PURPLE		:= \033[0;35m
TPUT 		= tput -T xterm-256color
_RESET 		:= $(shell $(TPUT) sgr0)
_BOLD 		:= $(shell $(TPUT) bold)

header:
	@printf "%b" "$(L_YELLOW)"
	@echo "																						"
	@echo "																						"
	@echo "				███╗   ███╗██╗███╗   ██╗██╗██╗  ██╗███████╗██╗     ██╗     				"
	@printf "%b" "$(YELLOW)"
	@echo "				████╗ ████║██║████╗  ██║██║██║  ██║██╔════╝██║     ██║     				"
	@echo "				██╔████╔██║██║██╔██╗ ██║██║███████║█████╗  ██║     ██║     				"
	@printf "%b" "$(RED)"
	@echo "				██║╚██╔╝██║██║██║╚██╗██║██║██╔══██║██╔══╝  ██║     ██║     				"
	@echo "				██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║███████╗███████╗███████╗				"
	@echo "				╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝				"
	@echo "									by Fmontel & Salabbe								"
	@echo "																						"
	@echo "		    								            								"
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo
