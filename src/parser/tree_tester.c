/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:19:03 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 14:59:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static char	*get_type_str(t_token_type type)
{
	size_t	i;
	size_t	cnt;

	char *type_str[] = {
		"WORD",
		"REDIR_IN",
		"REDOR_HEREDOC",
		"REDIR_OUT",
		"REDIR_APPEND",
		"PIPE",
		"PARENTHESIS_L",
		"PARENTHESIS_R",
		"AND",
		"OR",
		"WRONG"
	};

	i = 1;
	cnt = 0;
	while (!(i & type))
	{
		i <<= 1;
		cnt++;
	}
	return (type_str[cnt]);
}

void test_print(t_parse_tree *parse_tree);
void	test_side(t_parse_tree *parse_tree, t_move_direction dir)
{
	if (dir == RIGHT)
		parse_tree = parse_tree->right;
	if (dir == LEFT)
		parse_tree = parse_tree->left;
	test_print(parse_tree);
}

void	test_print(t_parse_tree *parse_tree)
{
	if (parse_tree == NULL)
	{
		return ;
	}
	printf("\n==============================================\n");
	printf("\nme : %p\n", parse_tree);
	printf("\n[tokens]\n");
	int cnt = 0;
	t_token *cp = parse_tree->token;
	printf("----------------------------------------------\n");
	if (!cp)
	{
		printf("  null token\n");
		printf("----------------------------------------------\n");
	}
	for (;cp;cp = cp->next)
	{
		printf("  token %d - type : %s\n", cnt, get_type_str(parse_tree->type));
		printf("  token %d - data : %s\n", cnt, cp->data);
		t_expanded_list *cpcp = cp->expanded_list;
		if (!cpcp)
			printf("  token %d - expanded list : not expanded\n", cnt);
		for (int j = 0;cpcp;j++, cpcp = cpcp->next)
			printf("  token %d - expanded_list %d - start : %zu, end : %zu \n", cnt, j, cpcp->start, cpcp->end);
		cnt++;
		printf("----------------------------------------------\n");
	}
	printf("\n");
	printf("up    : %p\n", parse_tree->up);
	printf("left  : %p\n", parse_tree->left);
	printf("right : %p\n", parse_tree->right);
	printf("\n==============================================\n");
	test_side(parse_tree, RIGHT);
	test_side(parse_tree, LEFT);
}
