/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:25:34 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 13:18:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static void	get_left_token_redirection(t_token *left_end, t_token *searched)
{
	if (searched->next->next)
	{
		left_end->next = searched->next->next;
		left_end->next->prev = left_end;
		searched->next->next = NULL;
	}
}

static void	set_left_end(t_token *token, t_token *searched)
{
	if (!token)
		return ;
	while (token && (token->next != searched))
		token = token->next;
	if (token)
		token->next = NULL;
}

void	get_left_node(t_parse_tree *parse_tree, t_token *searched)
{
	parse_tree->left = init_parse_tree();
	parse_tree->left->up = parse_tree;
	parse_tree->left->token = get_head_token(searched);
	if (parse_tree->left->token == searched)
		parse_tree->left->token = NULL;
	parse_tree->left->type = WORD;
	set_left_end(parse_tree->left->token, searched);
	searched->prev = NULL;
	if (searched->type & REDIRECTION_META)
		get_left_token_redirection(\
							get_tail_token(parse_tree->left->token), searched);
}

static void	set_right_end(t_token *right_end)
{
	right_end->next = NULL;
}

void	get_right_node(t_parse_tree *parse_tree, t_token *searched)
{
	parse_tree->right = init_parse_tree();
	parse_tree->right->up = parse_tree;
	parse_tree->right->token = searched->next;
	parse_tree->right->token->prev = NULL;
	parse_tree->right->type = WORD;
	searched->next = NULL;
	if (searched->type & REDIRECTION_META)
		set_right_end(parse_tree->right->token);
}
