# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 22:13:42 by jaham             #+#    #+#              #
#    Updated: 2022/03/23 22:18:46 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR			:=	src
BUILT_IN_DIR		:=	$(SRCS_DIR)/built_in
ENVP_DIR			:=	$(SRCS_DIR)/envp
EXECUTER_DIR		:=	$(SRCS_DIR)/executer
LEXER_DIR			:=	$(SRCS_DIR)/lexer
TERMINAL_DIR		:=	$(SRCS_DIR)/terminal
TOKENIZER_DIR		:=	$(SRCS_DIR)/tokenizer
UTILS_DIR			:=	$(SRCS_DIR)/utils

INCLUDE				:=	include
INCLUDE_FILES		:=	built_in.h color.h envp.h lexer.h parser.h terminal.h \
						tokenizer.h utils.h
INCLUDE_FILES		:=	$(addprefix $(INCLUDE)/, $(INCLUDE_FILES))

READLINE_DIR		:=	$(shell brew --prefix readline)
READLINE_INCLUDE	:=	$(READLINE_DIR)/include
READLINE_LIB		:=	$(READLINE_DIR)/lib

BUILT_IN_SRCS		:=	export.c unset.c env.c pwd.c exit.c cd.c cd_util.c \
						echo.c
BUILT_IN_SRCS		:=	$(addprefix $(BUILT_IN_DIR)/, $(BUILT_IN_SRCS))
ENVP_SRCS			:=	init_destroy.c util.c print.c tool.c
ENVP_SRCS			:=	$(addprefix $(ENVP_DIR)/, $(ENVP_SRCS))
EXEC_SRCS			:=
EXEC_SRCS			:=	$(addprefix $(EXECUTER_DIR)/, $(EXEC_SRCS))
LEXER_SRCS			:=	check_syntax_err.c \
						check_syntax_err_util.c print_syntax_err.c
LEXER_SRCS			:=	$(addprefix $(LEXER_DIR)/, $(LEXER_SRCS))
TOKENIZER_SRCS		:=	quote_mask.c token_manage.c tokenizer.c tokenizer_util.c
TOKENIZER_SRCS		:=	$(addprefix $(TOKENIZER_DIR)/, $(TOKENIZER_SRCS))
TERMINAL_SRCS		:=	check_default_state.c set_state.c signal_handler.c \
						init.c readline_loop.c check_valid_str.c \
						signal_handler_exec.c
TERMINAL_SRCS		:=	$(addprefix $(TERMINAL_DIR)/, $(TERMINAL_SRCS))
UTILS_SRCS			:=	exit_manage.c
UTILS_SRCS			:=	$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

MAIN_SRCS			:=	main.c
MAIN_SRCS			:=	$(addprefix $(SRCS_DIR)/, $(MAIN_SRCS))

LIBFT_DIR			:=	libft
LIBFT				:=	$(LIBFT_DIR)/libft.a

CC					:=	cc
CFLAGS				:=	-g
NAME				:=	minishell
SRCS				:=	$(BUILT_IN_SRCS) $(ENVP_SRCS) $(EXEC_SRCS) \
						$(LEXER_SRCS) $(TERMINAL_SRCS) $(TOKENIZER_SRCS) \
						$(UTILS_SRCS) $(MAIN_SRCS)
OBJS				:=	$(SRCS:.c=.o)
RM					:=	rm
RMFLAGS				:=	-f

.PHONY				:	all
all					:	$(NAME)

$(NAME)				:	$(OBJS) $(LIBFT) $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -o $@ $(LIBFT) $(OBJS) $(LIBFT) \
	-L$(READLINE_LIB) -lreadline -lhistory

$(LIBFT)			:
	cd $(LIBFT_DIR); make all

.PHONY				:	.c.o
.c.o				:
	$(CC) $(CFLAGS) -I$(READLINE_INCLUDE) -I$(INCLUDE) -I$(LIBFT_DIR) \
	-c $< -o $@

.PHONY				:	clean
clean				:
	$(RM) $(RMFLAGS) $(OBJS)
	cd $(LIBFT_DIR); make clean

.PHONY				:	fclean
fclean				:	clean
	$(RM) $(RMFLAGS) $(NAME) $(LIBFT)

.PHONY				:	re
re					:	fclean all