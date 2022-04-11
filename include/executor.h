/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:38:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:16:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include <sys/stat.h>

# define NOT_FOUND_MESSAGE "No such file or directory\n"
# define IS_DIR_MESSAGE "is a directory\n"
# define NO_PERMISSION_MESSAGE "Permission denied\n"
# define CMD_NOT_FOUND_MESSAGE "command not found\n"

// executor
void			executor(t_parse_tree *parse_tree, t_context *context);

// pid list
void			add_pid_list(t_pid_list **head, pid_t pid);
void			clear_pid_list(t_pid_list **head);
int				wait_pid_list(t_pid_list *head);
t_pid_list		*get_last_pid_list(t_pid_list *head);

// executor util
t_cmd_type		get_cmd_type(char *cmd);
int				get_exit_status(int stat);
int				check_redir_err(t_redir *redir);

// execute pipes
void			execute_pipes(t_pipes *pipes, t_context *context);

// execute pipeline
void			execute_pipeline(t_pipes *pipes, t_context *context);

// execute pipeline util
void			set_pipe_fd(t_pipes *pipes, int pipefd[2], int in);
void			wait_exit_fatal(t_pid_list *pids);
void			set_next_in(int pipefd[2], int *in);
t_exit_status	init_pipe(int pipefd[2]);
void			close_redir(t_redir *redir);

// init destory pipes
t_pipes			*init_pipes(char **cmd, t_redir *redir, \
													t_parse_tree *parse_tree);
void			add_pipes(t_pipes **head, t_pipes *new);
void			clear_pipes(t_pipes **head);

// make pipes
void			make_pipes(t_pipes **pipes, t_parse_tree *parse_tree);

// set redir
int				set_in_out(int in, int out);
int				restore_in_out(t_context *context);

// execute child
void			execute_child(t_pipes *pipes, t_context *context);

// exec built in
int				execute_built_in(t_cmd_type type, t_pipes *pipes, \
															t_context *context);

#endif