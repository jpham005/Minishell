/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:51 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 22:25:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <stddef.h>

static void	make_cmd_tree(t_cmd_tree **cmd_tree, \
								t_parse_tree *parse_tree, t_redir *redir);

static void	go_side_node(t_cmd_tree **cmd_tree, \
				t_parse_tree *parse_tree, t_move_direction dir, t_redir *redir)
{
	if (dir == RIGHT)
	{
		cmd_tree = &((*cmd_tree)->right);
		parse_tree = parse_tree->right;
	}
	if (dir == LEFT)
	{
		cmd_tree = &((*cmd_tree)->left);
		parse_tree = parse_tree->left;
	}
	make_cmd_tree(cmd_tree, parse_tree, redir);
}

static void	make_cmd_tree(t_cmd_tree **cmd_tree, \
									t_parse_tree *parse_tree, t_redir *redir)
{
	t_tree_type	new_type;
	char		**new_cmd;
	t_redir		*new_redir;

	if (!parse_tree)
		return ;
	new_type = get_tree_type(parse_tree->type);
	if (new_type == TREE_WRONG)
	new_cmd = get_tree_cmd(parse_tree);
	new_redir = get_tree_redir(parse_tree, redir);
	init_cmd_tree(new_type, new_cmd, new_redir);
	go_side_node(cmd_tree, parse_tree, RIGHT, new_redir);
	go_side_node(cmd_tree, parse_tree, LEFT, new_redir);
}

t_cmd_tree	*redirection(t_parse_tree *parse_tree)
{
	t_cmd_tree	*cmd_tree;

	make_cmd_tree(&cmd_tree, parse_tree, NULL);
}
