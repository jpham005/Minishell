/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 08:25:18 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 22:13:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static void parse_token_to_tree(t_cmd_tree **cmd_tree, t_token **tail);

static void	go_side_node(t_cmd_tree **cmd_tree, t_move_direction direction)
{
	t_token	*new_tail;

	if (direction == RIGHT)
		cmd_tree = &((*cmd_tree)->right);
	if (direction == LEFT)
		cmd_tree = &((*cmd_tree)->left);
	new_tail = get_tail_token((*cmd_tree)->token);
	parse_token_to_tree(cmd_tree, &new_tail);
}

static void	parse_token_to_tree(t_cmd_tree **cmd_tree, t_token **tail)
{
	t_token	*searched;

	remove_parenthesis_token(tail);
	if (find_meta(*tail, &searched, LOGICAL_META) == FOUND)
		insert_tree_node(cmd_tree, searched);
	else if (find_meta(*tail, &searched, PIPE_META) == FOUND)
		insert_tree_node(cmd_tree, searched);
	else if (find_meta(*tail, &searched, REDIRECTION_META) == FOUND)
		insert_tree_node(cmd_tree, searched);
	else
		return ;
	go_side_node(cmd_tree, RIGHT);
	go_side_node(cmd_tree, LEFT);

}
void test_print(t_cmd_tree *cmd_tree);
void	test_side(t_cmd_tree *cmd_tree, t_move_direction dir)
{
	if (dir == RIGHT)
		cmd_tree = cmd_tree->right;
	if (dir == LEFT)
		cmd_tree = cmd_tree->left;
	test_print(cmd_tree);
}

void	test_print(t_cmd_tree *cmd_tree)
{
	if (cmd_tree == NULL)
		return ;
	t_token *cp = cmd_tree->token;
	for (;cp;cp = cp->next)
	{
		printf("%s@", cp->data);
	}
	printf("\n");
	test_side(cmd_tree, RIGHT);
	test_side(cmd_tree, LEFT);
}

t_cmd_tree	*parser(t_token *token)
{
	t_cmd_tree	*cmd_tree;
	t_token		*tail;

	cmd_tree = NULL;
	tail = get_tail_token(token);
	parse_token_to_tree(&cmd_tree, &tail);
	printf("parse end\n");
	test_print(cmd_tree);
}
