/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:22:17 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 17:36:46 by jaham            ###   ########.fr       */
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
	printf("me : %p\n", parse_tree);
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
	}
	else{
	ssize_t readsize = read(parse_tree->redir->in, buf, 1000);
	write(1, buf, readsize);
	write(1, "\n", 1);
	}
	go_next_redir(parse_tree, 1);
	go_next_redir(parse_tree, 2);
}
