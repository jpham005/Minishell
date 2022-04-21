/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:21:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:28:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "color.h"
# include "t_types.h"
# include <termios.h>

# define SHELL_NAME "minishell: "
# define TOO_MANY_ARG_ERR_MESSAGE "Interactive only: "
# define SIG_QUIT_MESSAGE "Quit: 3\n"
# define SYNTAX_ERR_EXIT_STATUS 258

void		reset_terminal(t_context *context);
void		sig_int_handler_readline(int sig);
void		sig_int_handler_default(int sig);
void		set_sig_handler_child(void);
void		set_sig_handler_parent(t_pipes *pipes);
void		set_sig_handler_default(void);
void		heredoc_handler(int sig);
void		sig_quit_handler(int sig);
int			check_tty(int stdin, int stdout, int stderr);
void		shell_init(t_context *context, char **envp);
char		*ft_readline(t_context *context, char *str);
void		readline_loop(t_context *context);
int			check_valid_str(const char *str);
void		handle_syntax_err(t_context *context);
t_context	*make_context_static(t_context *context);
void		handle_heredoc_err(t_token **token);
t_token		*analize_line(char *line, t_context *context);
int			get_line(t_context *context, char **line);

#endif
