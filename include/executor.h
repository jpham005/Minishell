/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:38:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 10:32:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include <sys/stat.h>

typedef enum e_exit_status	t_exit_status;
typedef enum e_cmd_type		t_cmd_type;
typedef enum e_cmd_stat		t_cmd_stat;
typedef struct stat			t_stat;
typedef struct s_pid_list	t_pid_list;
typedef struct s_cmd_tree	t_cmd_tree;

enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_ERR = 125,
	PERM = 1,
	NOENT = 2,
};

enum e_cmd_type
{
	BUILT_IN_CD = 0,
	BUILT_IN_ECHO = 1,
	BUILT_IN_ENV = 2,
	BUILT_IN_EXIT = 3,
	BUILT_IN_EXPORT = 4,
	BUILT_IN_PWD = 5,
	BUILT_IN_UNSET = 6,
	NON_BUILT_IN = 7
};

enum e_cmd_stat
{
	FILE_NOT_FOUND = 0,
	IS_DIR,
	NO_PERMISSION,
	SUCCESS
};

struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

struct s_cmd_tree
{
	t_token_type	type;
	size_t			len;
};

# define NOT_FOUND_MESSAGE "No such file or directory\n"
# define IS_DIR_MESSAGE "is a directory\n"
# define NO_PERMISSION_MESSAGE "Permission denied\n"
# define CMD_NOT_FOUND_MESSAGE "command not found\n"

// executor
void			executor(t_parse_tree *parse_tree, t_context *context, \
														t_pid_list **pid_list);

// executor util
t_cmd_type		get_cmd_type(const char *data);
int				get_exit_status(int stat);
int				check_redir_err(t_redir *redir);

// execute cmd
void			execute_cmd(t_parse_tree *parse_tree, t_context *context);
void			execute_pipeline(t_parse_tree *parse_tree, t_context *context);

// execute bulit_in
int				try_exec_built_in(t_parse_tree *parse_tree, t_context *context);

// execute child
void			execute_child(t_parse_tree *parse_tree, t_context *context);

// set redir
int				set_in_out(int in, int out);
int				restore_in_out(t_context *context);

// pid list
void			add_pid_list(t_pid_list **head, pid_t pid);
void			clear_pid_list(t_pid_list **head);
int				wait_pid_list(t_pid_list *head);

// execute next node
void			execute_next_node(t_parse_tree *parse_tree, \
								t_context *context, t_pid_list **pid_list);
t_parse_tree	*get_next_node(t_parse_tree *parse_tree, t_move_direction dir);

// handle pipe
void			handle_pipe(t_parse_tree *parse_tree, t_context *context, \
														t_pid_list **pid_list);
void			set_pipe_fd(t_parse_tree *parse_tree, int in, int out, \
														t_move_direction dir);

#endif