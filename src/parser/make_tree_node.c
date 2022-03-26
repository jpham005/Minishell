/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:41:08 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 15:52:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_parse_tree	*init_parse_tree(void)
{
	t_parse_tree	*ret;

	ret = ft_malloc(sizeof(t_parse_tree), 1);
	ret->right = NULL;
	ret->left = NULL;
	ret->token = NULL;
	ret->type = WORD;
	ret->original_str = NULL;
	return (ret);
}

void	insert_tree_node(
	t_parse_tree **parse_tree, t_token *searched, t_parse_tree *prev_node
)
{
	t_parse_tree	*new_node;

	new_node = init_parse_tree();
	new_node->up = prev_node;
	new_node->token = searched;
	new_node->type = searched->type;
	get_left_node(new_node, searched);
	get_right_node(new_node, searched);
	if (*parse_tree)
		ft_free((void **) parse_tree);
	*parse_tree = new_node;
}
