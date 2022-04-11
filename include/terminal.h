/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:21:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:35:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "color.h"
# include "envp.h"
# include <termios.h>

# define SHELL_NAME "minishell: "
# define TOO_MANY_ARG_ERR_MESSAGE "Too many arg: "
# define SIG_QUIT_MESSAGE "Quit: 3\n"
# define MINISHELL_WITH_COLOR PURPLE_BD"minishell "PINK_BD"#"DEF_COL" "BLUE_BT
# define MINISHELL_WITH_COLOR_ERR PURPLE_BD"minishell "RED"#"DEF_COL" "BLUE_BT
# define SYNTAX_ERR_EXIT_STATUS 258

void		reset_terminal(t_context *context);
void		sig_int_handler_readline(int sig);
void		sig_int_handler_default(int sig);
void		set_sig_handler_child(void);
void		set_sig_handler_parent(t_pipes *pipes);
void		set_sig_handler_default(void);
void		heredoc_handler(int sig);
void		sig_quit_handler(int sig);
int			check_arg(int argc, const char **argv);
int			check_tty(int stdin, int stdout, int stderr);
void		init_shell(t_context *context, const char **envp);
char		*ft_readline(t_context *context, char *str);
void		readline_loop(t_context *context);
int			check_valid_str(const char *str);
void		handle_syntax_err(t_context *context);
t_context	*make_context_static(t_context *context);

#endif
