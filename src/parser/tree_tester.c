/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:19:03 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 15:59:58 by jaham            ###   ########.fr       */
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
	printf("==============================================\n");
	printf("me : %lld\n", (long long) parse_tree % 100000);
	printf("  token type : %s\n", get_type_str(parse_tree->type));
	printf("  token : ");
	t_token *cp = parse_tree->token;
	if (!cp)
		printf("null token@");
	for (;cp;cp = cp->next)
	{
		printf("%s ", cp->data);
	}
	printf("\n");
	printf("up : %lld\n", (long long) parse_tree->up % 100000);
	printf("left : %lld\n", (long long) parse_tree->left % 100000);
	printf("right : %lld\n", (long long) parse_tree->right % 100000);
	printf("==============================================\n");
	test_side(parse_tree, RIGHT);
	test_side(parse_tree, LEFT);
}
