# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 20:31:22 by hyeonpar          #+#    #+#              #
#    Updated: 2022/03/22 19:29:53 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c ft_strncmp.c ft_putstr_fd.c ft_free.c ft_malloc.c \
	ft_strdup.c ft_substr.c ft_memcpy.c ft_strjoin.c free_c_dptr.c ft_split.c \
	ft_strchr.c ft_isalpha.c ft_isnum.c ft_fork.c perror_exit.c ft_isnumstr.c \
	ft_atoi.c ft_getcwd.c get_next_line.c get_next_line_util.c ft_waitpid.c \
	ft_wifexited.c ft_wexitstatus.c ft_wifsignaled.c ft_wtermsig.c \
	exit_by_errno.c ft_pipe.c ft_dup2.c ft_strcmp.c ft_close.c exit_with_msg.c \
	ft_dup.c ft_strlcpy.c ft_strnstr.c ft_bzero.c ft_calloc.c ft_memset.c \
	ft_isdigit.c ft_itoa.c ft_strtrim.c ft_isspace.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm
RMFLAGS = -f
NAME = libft.a

.PHONY	:	all
all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.PHONY	:	.c.o
.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	:	clean
clean	:
	$(RM) $(RMFLAGS) $(OBJS)

.PHONY	:	fclean
fclean	:	clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY	:	re
re	:	fclean all
