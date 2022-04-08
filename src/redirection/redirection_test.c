/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:22:17 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 21:31:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <stdio.h>
#include <unistd.h>
void	test_redir(t_parse_tree *parse_tree);
static void	go_next_redir(t_parse_tree *parse_tree, int a)
{
	if (a == 1)
		parse_tree = parse_tree->left;
	else
		parse_tree = parse_tree->right;
	test_redir(parse_tree);
}

void	test_redir(t_parse_tree *parse_tree)
{
	char	buf[1000];

	if (!parse_tree)
		return ;
	printf("\n==================================================================\n");
	printf("me : %p\n", parse_tree);
	if (!parse_tree->token)
		printf("null token\n");
	else if (parse_tree->token->data)
		printf("token data : %s\n", parse_tree->token->data);

	printf("\n---------------------------------------------------------------------\n");
	if (!parse_tree->redir)
	{
		printf("NULL REDIR\n");
		return ;
	}
	if (parse_tree->redir->err)
	{
		printf("minihsell: %s: %s\n", parse_tree->redir->err_target, parse_tree->redir->err);
		return ;
	}
	else if (parse_tree->redir->in == 0)
	{
		printf("stdin\n");
		printf("redir out : %d\n", parse_tree->redir->out);
	}
	else{
		printf("redir in  : %d\n", parse_tree->redir->in);
		printf("redir out : %d\n", parse_tree->redir->out);
	// printf("-------------\n");
	// ssize_t readsize = read(parse_tree->redir->in, buf, 1000);
	// write(1, buf, readsize);
	// write(1, "@end\n", 5);
	}
	go_next_redir(parse_tree, 1);
	go_next_redir(parse_tree, 2);
}
