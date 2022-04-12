/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:20:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 08:58:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "t_types.h"

# define TOKEN_ERR_MESSAGE "ambiguous redirect\n"

// redirection
t_redir_result	redirection(t_parse_tree *parse_tree, t_redir *redir, \
														t_context *context);

// redirection util
int				check_valid_redir_target(t_parse_tree *parse_tree);
void			set_redir_err(t_parse_tree *parse_tree, char *err_target, \
																	char *err);
int				is_multiple_redir(t_parse_tree *parse_tree, t_redir_types type);

// init destroy redir
t_redir			*init_redir(int in, int out, char *err, char *err_target);
void			destroy_redir(t_redir **redir);
t_redir			*copy_redir(t_redir *redir);

// get redir in
t_redir_result	get_redir_in(t_parse_tree *parse_tree);

// get redir out
void			get_redir_out(t_parse_tree *parse_tree);

#endif
