/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:38:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 22:53:41 by jaham            ###   ########.fr       */
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
typedef struct s_pipes		t_pipes;
typedef struct s_pid_list	t_pid_list;

enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_FATAL = 1,
	EXIT_ERR = 125,
	PERM = 1,
	NOENT = 2,
	EXIT_SIGNAL = 128,
	STOP_SIGNAL = 17,
	CONTINUE_SIGNAL = 19,
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

struct s_pipes
{
	char	**cmd;
	t_redir	*redir;
	t_pipes	*next;
};

struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

# define NOT_FOUND_MESSAGE "No such file or directory\n"
# define IS_DIR_MESSAGE "is a directory\n"
# define NO_PERMISSION_MESSAGE "Permission denied\n"
# define CMD_NOT_FOUND_MESSAGE "command not found\n"

// executor
void		executor(t_parse_tree *parse_tree, t_context *context);

// init destory pipes
t_pipes		*init_pipes(char **cmd, t_redir *redir);
void		add_pipes(t_pipes **head, t_pipes *new);
void		clear_pipes(t_pipes **head);

// execute next node
void		execute_next_node(t_parse_tree *parse_tree, t_context *context);

// pid list
void		add_pid_list(t_pid_list **head, pid_t pid);
void		clear_pid_list(t_pid_list **head);
int			wait_pid_list(t_pid_list *head);

// executor util
t_cmd_type	get_cmd_type(const char *cmd);
int			get_exit_status(int stat);
int			check_redir_err(t_redir *redir);

// execute child
void		execute_child(t_pipes *pipes, t_context *context);

// execute pipes
void		execute_pipes(t_pipes *pipes, t_context *context);
void		execute_pipeline(t_pipes *pipes, t_context *context);

// make pipes
void		make_pipes(t_pipes **pipes, t_parse_tree *parse_tree);

// set redir
int			set_in_out(int in, int out);
int			restore_in_out(t_context *context);

// exec built in
int			exec_built_in(t_cmd_type type, t_parse_tree *parse_tree, \
															t_context *context);

#endif