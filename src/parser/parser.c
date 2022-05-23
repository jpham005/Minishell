/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 08:25:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 21:05:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "tokenizer.h"
#include "t_move.h"
#include <stdlib.h>

static void	parse_token_to_tree(t_parse_tree **parse_tree, t_token **tail, \
													t_parse_tree *prev_node);

static void	go_side_node(t_parse_tree **parse_tree, t_move_direction direction)
{
	t_token			*new_tail;
	t_parse_tree	*prev_node;

	prev_node = *parse_tree;
	if (direction == RIGHT)
		parse_tree = &((*parse_tree)->right);
	if (direction == LEFT)
		parse_tree = &((*parse_tree)->left);
	new_tail = get_tail_token((*parse_tree)->token);
	parse_token_to_tree(parse_tree, &new_tail, prev_node);
}

static void	insert_single_word_node(t_parse_tree **parse_tree, t_token *token)
{
	*parse_tree = init_parse_tree();
	(*parse_tree)->token = token;
}

static void	parse_token_to_tree(
	t_parse_tree **parse_tree, t_token **tail, t_parse_tree *prev_node
)
{
	t_token	*searched;

	remove_parenthesis_token(tail, parse_tree);
	if (find_meta(*tail, &searched, LOGICAL_META) == FOUND)
		insert_tree_node(parse_tree, searched, prev_node);
	else if (find_meta(*tail, &searched, PIPE_META) == FOUND)
		insert_tree_node(parse_tree, searched, prev_node);
	else if (find_meta(*tail, &searched, REDIRECTION_META) == FOUND)
		insert_tree_node(parse_tree, searched, prev_node);
	else if (!(*parse_tree) && *tail)
	{
		insert_single_word_node(parse_tree, get_head_token(*tail));
		*tail = NULL;
		return ;
	}
	else
		return ;
	go_side_node(parse_tree, RIGHT);
	go_side_node(parse_tree, LEFT);
}

t_parse_tree	*parser(t_token *token)
{
	t_parse_tree	*parse_tree;
	t_token			*tail;

	parse_tree = NULL;
	tail = get_tail_token(token);
	parse_token_to_tree(&parse_tree, &tail, NULL);
	return (parse_tree);
}
