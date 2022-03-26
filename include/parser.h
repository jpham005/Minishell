/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:51:43 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 15:52:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"

typedef struct e_parse_tree		t_parse_tree;
typedef enum e_search_result	t_search_result;
typedef enum e_meta_type		t_meta_type;
typedef enum e_move_direction	t_move_direction;

struct e_parse_tree
{
	t_parse_tree	*up;
	t_parse_tree	*left;
	t_parse_tree	*right;
	t_token			*token;
	t_token_type	type;
	char			*original_str;
};

enum e_search_result
{
	FOUND = 0,
	NOT_FOUND
};

enum e_meta_type
{
	LOGICAL_META = AND | OR,
	PIPE_META = PIPE,
	REDIRECTION_META = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	NOT_META = 0
};

enum e_move_direction
{
	RIGHT = 0,
	LEFT
};

// get parser tree
t_parse_tree	*parser(t_token *token);

// remove parenthesis token
void			remove_parenthesis_token(t_token **tail);

// find meta type
t_search_result	find_meta(t_token *tail, t_token **searched, t_meta_type type);

// make tree node
void			insert_tree_node(t_parse_tree **parse_tree, t_token *searched, \
													t_parse_tree *prev_node);

// get splited token
void			get_left_node(t_parse_tree *parse_tree, t_token *searched);
void			get_right_node(t_parse_tree *parse_tree, t_token *searched);

// manage cmd tree
t_parse_tree	*init_parse_tree(void);

#endif