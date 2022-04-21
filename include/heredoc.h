/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:21:34 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:20:05 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "t_token.h"
# include "t_context.h"
# include "t_heredoc.h"
# include "t_buffer.h"

# define HEREDOC_WRITE_ERR_MESSAGE "write err while heredoc\n"

// heredoc
int				heredoc(t_token *token, t_context *context);

// handle heredoc
t_redir_result	handle_heredoc(t_token *token, t_context *context);

// heredoc util
void			set_heredoc_info(char *str, t_heredoc *heredoc, \
															t_buffer *buffer);
int				is_heredoc_end(char *input, char *limit);
void			set_cursur_heredoc(void);
void			write_heredoc_string(char *input, int fd);
int				is_heredoc(t_token *token);

// heredoc end
int				end_heredoc(char **input, int here_pipe[2]);

#endif
