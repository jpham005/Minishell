/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:20:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 22:09:25 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "parser.h"

# define TOKEN_ERR_MESSAGE "ambiguous redirect\n"

typedef enum e_redir_types	t_redir_types;

enum e_redir_types
{
	REDIR_TYPE = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	REDIR_INS = REDIR_IN | REDIR_HEREDOC,
	REDIR_OUTS = REDIR_OUT | REDIR_APPEND
};

// redirection
t_redir_result	redirection(t_parse_tree *parse_tree, t_redir *redir, \
														t_context *context);

// redirection util
int				check_valid_redir_target(t_parse_tree *parse_tree);
void			set_redir_err(t_parse_tree *parse_tree, char *err_target, \
																	char *err);
t_redir			*init_redir(void);
void			destroy_redir(t_redir **redir);
int				is_multiple_redir(t_parse_tree *parse_tree, t_token_type type);
// get redir in
t_redir_result	get_redir_in(t_parse_tree *parse_tree);

// get redir out
void			get_redir_out(t_parse_tree *parse_tree);

#endif
