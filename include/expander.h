/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:59:05 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:54:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "types/t_quote.h"
# include "types/t_name.h"
# include "types/t_token.h"
# include "types/t_parse_tree.h"
# include "types/t_buffer.h"
# include "types/t_context.h"

// expander
void		expander(t_parse_tree *parse_tree, t_context *context);

// expander util
void		substitute_data(t_parse_tree *parse_tree, t_token **token, \
															t_buffer *buffer);
void		append_expanded(t_buffer *buffer, char *expanded_data, \
												size_t start, t_token *token);
int			is_in_range_index(size_t start, size_t end, size_t index);
void		del_token_from_tree(t_parse_tree *parse_tree, t_token *token);

// expand shell param
void		expand_shell_param(t_token *token, t_buffer *buffer, \
											t_context *context, int is_heredoc);
void		expand_with_envp(t_token *token, t_buffer *buffer, \
												t_context *context, size_t *i);
void		expand_with_exit_status(t_token *token, t_buffer *buffer, \
												t_context *context, size_t *i);

// word spliting
void		word_split(t_parse_tree *parse_tree, t_token **token);

// word spliting util
void		check_quote_expanded(t_token *token, t_quote_mask *mask, \
																size_t index);
void		substitute_token(t_parse_tree *parse_tree, t_token **token, \
														t_token *new_token);

// expand asterisk
void		expand_asterisk(t_parse_tree *parse_tree, t_token *token);

// get fixed data
void		get_fixed_data(t_parse_tree *parse_tree, t_filename **head, \
																t_token *token);
int			is_valid_quote(char c, t_expanded_list *expanded_list, size_t i, \
															t_quote_mask *mask);

// get curr files
void		get_curr_files(t_filename **curr_files);

// peform asterisk expansion
void		perform_asterisk_expansion(t_filename *fixed_data, \
													t_filename **curr_files);

// filename list
t_filename	*init_filename(char *filename, t_nametype type);
void		add_filename(t_filename **head, char *str, t_nametype type);
void		del_one_filename(t_filename **head, t_filename *target);
void		clear_filename(t_filename **head);

#endif
