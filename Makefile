# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 22:13:42 by jaham             #+#    #+#              #
#    Updated: 2022/04/13 13:59:37 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR			:=	src
BUILT_IN_DIR		:=	$(SRCS_DIR)/built_in
ENVP_DIR			:=	$(SRCS_DIR)/envp
EXECUTOR_DIR		:=	$(SRCS_DIR)/executor
EXPANDER_DIR		:=	$(SRCS_DIR)/expander
HEREDOC_DIR			:=	$(SRCS_DIR)/heredoc
LEXER_DIR			:=	$(SRCS_DIR)/lexer
REDIRECTION_DIR		:=	$(SRCS_DIR)/redirection
PARSER_DIR			:=	$(SRCS_DIR)/parser
TERMINAL_DIR		:=	$(SRCS_DIR)/terminal
TOKENIZER_DIR		:=	$(SRCS_DIR)/tokenizer
UTILS_DIR			:=	$(SRCS_DIR)/utils

INCLUDE				:=	include
INCLUDE_FILES		:=	built_in.h color.h envp.h executor.h expander.h \
						heredoc.h lexer.h parser.h terminal.h redirection.h \
						t_buffer.h t_types.h tokenizer.h utils.h
INCLUDE_FILES		:=	$(addprefix $(INCLUDE)/, $(INCLUDE_FILES))

READLINE_DIR		:=	readline
READLINE_INCLUDE	:=	$(READLINE_DIR)
READLINE_LIB		:=	$(READLINE_DIR)

BUILT_IN_SRCS		:=	export.c unset.c env.c pwd.c exit.c exit_util.c \
						cd.c cd_util.c echo.c
BUILT_IN_SRCS		:=	$(addprefix $(BUILT_IN_DIR)/, $(BUILT_IN_SRCS))
ENVP_SRCS			:=	init_destroy.c util.c print.c tool.c
ENVP_SRCS			:=	$(addprefix $(ENVP_DIR)/, $(ENVP_SRCS))
EXECUTOR_SRCS		:=	executor.c executor_util.c t_pipes.c \
						pid_list.c execute_child.c execute_pipes.c \
						execute_pipeline.c make_pipes.c set_redir.c \
						execute_built_in.c execute_pipeline_util.c \
						execute_logical.c
EXECUTOR_SRCS		:=	$(addprefix $(EXECUTOR_DIR)/, $(EXECUTOR_SRCS))
EXPANDER_SRCS		:=	expander.c expander_util.c expand_shell_param.c \
						expand_with_envp.c expand_with_exit_status.c \
						word_split.c word_split_util.c expand_asterisk.c \
						get_fixed_data.c filename_list.c get_curr_files.c \
						perform_asterisk_expansion.c
EXPANDER_SRCS		:=	$(addprefix $(EXPANDER_DIR)/, $(EXPANDER_SRCS))
HEREDOC_SRCS		:=	heredoc.c handle_heredoc.c heredoc_util.c heredoc_end.c
HEREDOC_SRCS		:=	$(addprefix $(HEREDOC_DIR)/, $(HEREDOC_SRCS))
LEXER_SRCS			:=	lexer.c check_near_token_err.c \
						check_near_token_err_util.c check_token_by_place.c \
						check_special_type_syntax.c check_match_err.c \
						lexer_err_info_manage.c
LEXER_SRCS			:=	$(addprefix $(LEXER_DIR)/, $(LEXER_SRCS))
REDIRECTION_SRCS	:=	redirection.c redirection_util.c get_redir_in.c \
						get_redir_out.c init_destroy_redir.c
REDIRECTION_SRCS	:=	$(addprefix $(REDIRECTION_DIR)/, $(REDIRECTION_SRCS))
PARSER_SRCS			:=	parser.c remove_parenthesis_token.c find_meta.c \
						get_new_token.c init_destroy_tree.c
PARSER_SRCS			:=	$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))
TERMINAL_SRCS		:=	ft_readline.c signal_handler.c \
						minishell_init.c readline_loop.c check_valid_str.c \
						signal_handler_exec.c readline_loop_util.c
TERMINAL_SRCS		:=	$(addprefix $(TERMINAL_DIR)/, $(TERMINAL_SRCS))
TOKENIZER_SRCS		:=	quote_mask.c t_token_init_destroy.c t_token_tool.c \
						t_token_init_destroy_util.c tokenizer.c \
						tokenizer_util.c
TOKENIZER_SRCS		:=	$(addprefix $(TOKENIZER_DIR)/, $(TOKENIZER_SRCS))
UTILS_SRCS			:=	exit_manage.c t_buffer.c
UTILS_SRCS			:=	$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

MAIN_SRCS			:=	main.c
MAIN_SRCS			:=	$(addprefix $(SRCS_DIR)/, $(MAIN_SRCS))

LIBFT_DIR			:=	libft
LIBFT				:=	$(LIBFT_DIR)/libft.a

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -D READLINE_LIBRARY -g# -fsanitize=address
NAME				:=	minishell
SRCS				:=	$(BUILT_IN_SRCS) $(ENVP_SRCS) $(EXECUTOR_SRCS) \
						$(EXPANDER_SRCS) $(HEREDOC_SRCS) $(LEXER_SRCS) \
						$(REDIRECTION_SRCS) $(PARSER_SRCS) $(TERMINAL_SRCS) \
						$(TOKENIZER_SRCS) $(UTILS_SRCS) $(MAIN_SRCS)
OBJS				:=	$(SRCS:.c=.o)
RM					:=	rm
RMFLAGS				:=	-f

.PHONY				:	all
all					:	$(NAME)

$(NAME)				:	$(OBJS) $(LIBFT) $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -o $@ $(LIBFT) $(OBJS) $(LIBFT) \
	-L$(READLINE_LIB) -lreadline -lhistory -lncurses

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
