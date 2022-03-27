/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:59:05 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 18:28:46 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "parser.h"
# include "t_buffer.h"
# include "terminal.h"

typedef struct s_filename t_filename;

struct s_filename
{
	char		*name;
	t_filename	*next;
};

// expander
void	expander(t_parse_tree *parse_tree, t_context *context);

// expander util
void	substitute_data(t_token *token, t_buffer *buffer);
void	append_expanded(t_buffer *buffer, char *expanded_data, \
												size_t start, t_token *token);

// expand shell param
void	expand_shell_param(t_token *token, t_buffer *buffer, \
															t_context *context);
void	expand_with_envp(t_token *token, t_buffer *buffer, t_context *context, \
																	size_t *i);
void	expand_with_exit_status(t_token *token, t_buffer *buffer, \
												t_context *context, size_t *i);

// expand asterisk
void	expand_asterisk(t_token *token, t_buffer *buffer);

#endif