/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:51:43 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 16:29:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"

typedef struct s_cmd_tree		t_cmd_tree;
typedef enum e_search_result	t_search_result;
typedef enum e_meta_type		t_meta_type;
typedef enum e_move_direction	t_move_direction;

struct s_cmd_tree
{
	t_cmd_tree		*up;
	t_cmd_tree		*left;
	t_cmd_tree		*right;
	t_token			*token;
	t_token_type	type;
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
t_cmd_tree		*parser(t_token *token);

// remove parenthesis token
void			remove_parenthesis_token(t_token **tail);

// find meta type
t_search_result	find_meta(t_token *tail, t_token **searched, t_meta_type type);

// make tree node
void			insert_tree_node(t_cmd_tree **cmd_tree, t_token *searched);

// get splited token
void			get_left_token(t_cmd_tree *cmd_tree, t_token *searched);
void			get_right_token(t_cmd_tree *cmd_tree, t_token *searched);

// manage cmd tree
t_cmd_tree		*init_cmd_tree(void);

#endif