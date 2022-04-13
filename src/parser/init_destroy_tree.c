/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:41:08 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 11:05:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "tokenizer.h"

t_parse_tree	*init_parse_tree(void)
{
	t_parse_tree	*ret;

	ret = ft_malloc(sizeof(t_parse_tree), 1);
	ft_memset(ret, 0, sizeof(t_parse_tree));
	ret->type = WORD;
	return (ret);
}

static void	set_new_node_info(
	t_parse_tree *new_node, t_parse_tree *prev_node, t_token *searched
)
{
	new_node->up = prev_node;
	new_node->token = searched;
	new_node->type = searched->type;
}

void	insert_tree_node(
	t_parse_tree **parse_tree, t_token *searched, t_parse_tree *prev_node
)
{
	t_parse_tree	*new_node;

	new_node = init_parse_tree();
	set_new_node_info(new_node, prev_node, searched);
	get_left_node(new_node, searched);
	get_right_node(new_node, searched);
	if (*parse_tree)
		ft_free((void **) parse_tree);
	*parse_tree = new_node;
}

static void	clear_redir(t_parse_tree *parse_tree)
{
	if (!parse_tree->redir)
		return ;
	ft_free((void **) &(parse_tree->redir->err));
	ft_free((void **) &(parse_tree->redir->err_target));
	ft_free((void **) &(parse_tree->redir));
}

void	clear_parse_tree(t_parse_tree **parse_tree)
{
	t_parse_tree	*left;
	t_parse_tree	*right;

	if (!*parse_tree)
		return ;
	left = (*parse_tree)->left;
	right = (*parse_tree)->right;
	clear_fd((*parse_tree)->token);
	clear_token(&((*parse_tree)->token));
	clear_redir(*parse_tree);
	ft_free((void **) &((*parse_tree)->original_str));
	ft_free((void **) parse_tree);
	clear_parse_tree(&left);
	clear_parse_tree(&right);
}
