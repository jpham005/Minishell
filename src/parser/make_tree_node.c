/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:41:08 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 21:24:24 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_cmd_tree	*init_cmd_tree(void)
{
	t_cmd_tree	*ret;

	ret = ft_malloc(sizeof(t_cmd_tree), 1);
	ret->right = NULL;
	ret->left = NULL;
	ret->token = NULL;
	ret->type = WORD;
	return (ret);
}

void	insert_tree_node(t_cmd_tree **cmd_tree, t_token *searched)
{
	t_cmd_tree	*new_node;

	new_node = init_cmd_tree();
	new_node->token = searched;
	new_node->type = searched->type;
	get_left_token(new_node, searched);
	get_right_token(new_node, searched);
	if (*cmd_tree)
		ft_free((void **) cmd_tree);
	*cmd_tree = new_node;
}
