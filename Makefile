# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:41:03 by salabbe           #+#    #+#              #
#    Updated: 2025/05/13 19:44:00 by salabbe          ###   ########.fr        #
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
					srcs/initializer.c 								\
					srcs/sigs.c 									\
					srcs/closing.c 									\
					srcs/controller_exec.c							\
					srcs/prompt/prompt_controller.c 				\
					srcs/tokenization/cmdlist_free.c 				\
					srcs/tokenization/ctn_lit.c 					\
					srcs/tokenization/ctn_smbl.c 					\
					srcs/tokenization/cmd_toarr.c 					\
					srcs/tokenization/expander.c 					\
					srcs/tokenization/init_cmd.c 					\
					srcs/tokenization/tk_init.c 					\
					srcs/tokenization/str_env.c						\
					srcs/tokenization/tk_type_set.c					\
					srcs/tokenization/cmd_tostart.c					\
					srcs/tokenization/tokenizer.c 					\
					srcs/tokenization/rem_lit.c 					\
					srcs/debug/log_controller.c 					\
					srcs/debug/print_controller.c 					\
					srcs/debug/print_tokens.c			 			\
					srcs/debug/print_cmds.c			 				\
					srcs/builtins/ft_cd.c							\
					srcs/builtins/ft_export.c						\
					srcs/builtins/builtin_utils.c					\
					srcs/builtins/ft_echo.c							\
					srcs/exec/envp_controller.c						\
					srcs/exec/exec.c								\

N_OBJS		=	$(MANDATORY:%.c=.build/%.o)
DEPS		=	$(N_OBJS:%.o=%.d)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
CPPFLAGS	=	-MP	-MMD -Iinclude									\
				-Ilibft/libft.a										\
				-Iheaders/minishell.h								\
				-Iheaders/debug.h									\

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
		@printf "$(L__PUR)CREATED$(OFF) $(LB_CYA)OBJS$(_RESET) $(L__CYA)in ~/.build$(OFF)\n"
		@printf "$(L__PUR)CREATED$(OFF) $(L__CYA)$(N_NAME)$(OFF)\n"

$(LIBFT):
		$(MAKE) -C libft

lre:
		@printf "$(LB_PUR)RE-MAKING LIBFT$(OFF)\n"
		$(MAKE) -C libft re

.build/%.o: %.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

-include $(DEPS)

lclean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		$(MAKE) -C libft clean
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"

clean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		$(MAKE) -C libft clean
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"
		@printf "$(L__CYA)	~/.build$(OFF)\n"
		rm -rf .build

fclean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"
		$(MAKE) -C libft fclean
		@printf "$(L__CYA)	~/.build$(OFF)\n"
		@printf "$(L__CYA)	~/$(N_NAME)$(OFF)\n"
		rm -rf $(N_NAME)
		@printf "$(L__CYA)	~/controller.log$(OFF)\n"
		@printf "$(L__CYA)	~/tokens.log$(OFF)\n"
		@printf "$(L__CYA)	~/cmds.log$(OFF)\n"
		rm -rf .build controller.log tokens.log cmds.log

re:
		@printf "$(_B_RED)RE-STARTED FROM SCRATCH$(OFF)$(_RESET)\n"
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re lre

# **************************************************************************** #
#								    										   #
#			    	=======>		PIMPER			<=======		   		   #
#																			   #
# **************************************************************************** #


___WHI		:= \033[0m
___RED		:= \033[0;31m
___YEL		:= \033[0;33m
___GRE		:= \033[0;32m
___CYA		:= \033[0;36m
___PUR		:= \033[0;35m
_B_RED		:= \033[1;31m
_B_GRE		:= \033[1;32m
_B_YEL		:= \033[1;33m
_B_CYA		:= \033[1;36m
_B_PUR		:= \033[1;35m
L__PUR		:= \033[0;95m
L__RED		:= \033[0;91m
L__YEL		:= \033[0;93m
L__CYA		:= \033[0;96m
LB_RED		:= \033[1;91m
LB_PUR		:= \033[1;95m
LB_YEL		:= \033[1;93m
LB_CYA		:= \033[1;96m
TPUT 		= tput -T xterm-256color
_RESET 		:= $(shell $(TPUT) sgr0)
_BOLD 		:= $(shell $(TPUT) bold)

header:
	@printf "$(_B_RED)"
	@echo "																						"
	@echo "				           ██╗          ██╗        ███████╗        ██╗					"
	@echo "				███╗   ███╗██║███╗   ██╗██║██╗  ██╗██╔════╝██╗     ██║     				"
	@printf "$(LB_RED)"
	@echo "				████╗ ████║██║████╗  ██║██║██║  ██║█████╗  ██║     ██║     				"
	@echo "				██╔████╔██║██║██╔██╗ ██║██║███████║██╔══╝  ██║     ██║     				"
	@printf "$(_B_RED)"
	@echo "				██║╚██╔╝██║██║██║╚██╗██║██║██╔══██║███████╗██║     ███████╗				"
	@echo "				██║ ╚═╝ ██║╚═╝██║ ╚████║╚═╝██║  ██║╚══════╝███████╗╚══════╝				"
	@echo "				╚═╝     ╚═╝   ╚═╝  ╚═══╝   ╚═╝  ╚═╝        ╚══════╝						"
	@printf "$(L__RED)"
	@echo "									by Fmontel & Salabbe								"
	@printf "$(___WHI)"
	@echo "																						"
	@echo "		    								            								"
	@echo
	@printf "$(L__CYA)CC:	$(L__YEL)$(CC)\n"
	@printf "$(L__CYA)CFlags:	$(L__YEL)$(CFLAGS)\n"
	@printf "$(___WHI)"
	@echo
