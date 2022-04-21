/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:21:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:31:43 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "color.h"
# include "t_term.h"
# include "t_context.h"
# include "t_pipes.h"
# include "t_context.h"

# define SHELL_NAME "minishell: "
# define TOO_MANY_ARG_ERR_MESSAGE "Interactive only: "
# define SIG_QUIT_MESSAGE "Quit: 3\n"
# define MINISHELL_WITH_COLOR "\001\033[1;38;5;147m\002minishell \
				\001\033[1;38;5;219m\002#\001\033[m\002 \001\033[38;5;153m\002"
# define MINISHELL_WITH_COLOR_ERR "\001\033[1;38;5;147m\002minishell \
				\001\033[1;38;5;203m\002#\001\033[m\002 \001\033[38;5;153m\002"
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
