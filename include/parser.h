/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:51:43 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:54:20 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types/t_parse_tree.h"
# include "types/t_search.h"
# include "types/t_meta.h"

// get parser tree
t_parse_tree	*parser(t_token *token);

// remove parenthesis token
void			remove_parenthesis_token(t_token **tail);

// find meta type
t_search_result	find_meta(t_token *tail, t_token **searched, t_meta_type type);

// init destroy tree
void			insert_tree_node(t_parse_tree **parse_tree, t_token *searched, \
													t_parse_tree *prev_node);
void			clear_parse_tree(t_parse_tree **parse_tree);

// get splited token
void			get_left_node(t_parse_tree *parse_tree, t_token *searched);
void			get_right_node(t_parse_tree *parse_tree, t_token *searched);

// manage cmd tree
t_parse_tree	*init_parse_tree(void);

#endif
