/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:20:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 21:12:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "parser.h"
# include "t_buffer.h"
# include "terminal.h"

# define REDIR_TYPE (REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND)
# define TOKEN_ERR_MESSAGE "ambiguous redirect\n"

typedef enum e_redir_result	t_redir_result;
typedef struct s_heredoc	t_heredoc;
typedef enum e_is_quoted	t_is_quoted;

enum e_redir_result
{
	REDIR_SUCCESS = 0,
	REDIR_ERROR
};

enum e_is_quoted
{
	NOT_QUOTED = 0,
	QUOTED
};

struct s_heredoc
{
	char			*limit;
	t_is_quoted		quoted;
};

// redirection
t_redir_result	redirection(t_parse_tree *parse_tree, t_redir *redir, \
														t_context *context);

// redirection util
int				check_valid_redir_target(t_parse_tree *parse_tree);
void			set_redir_err(t_parse_tree *parse_tree, char *err_target, \
																	char *err);

// get redir in
t_redir_result	get_redir_in(t_parse_tree *parse_tree, t_context *context);

// heredoc
t_redir_result	handle_redir_heredoc(t_parse_tree *parse_tree, \
														t_context *context);

// heredoc util
void			set_heredoc_info(char *str, t_heredoc *heredoc, \
															t_buffer *buffer);
int				is_heredoc_end(char *input, char *limit);
void			set_cursur_heredoc(void);
int				write_heredoc_string(char *input, int fd);

// heredoc return
int				close_return_pipe(int here_pipe[2]);
int				return_heredoc_err(t_parse_tree *parse_tree, \
														t_heredoc *heredoc);
int				end_heredoc(char **input, int here_pipe[2]);

#endif
