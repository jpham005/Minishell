/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:36:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/10 11:54:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "redirection.h"
#include <stddef.h>

void	make_pipes(t_pipes **pipes, t_parse_tree *parse_tree)
{
	if (!parse_tree)
		return ;
	if (parse_tree->type & (AND | OR))
		add_pipes(pipes, init_pipes(NULL, NULL, parse_tree));
	if (parse_tree->type & WORD)
		add_pipes(pipes, init_pipes(convert_token_to_dptr(parse_tree->token), \
									copy_redir(parse_tree->redir), NULL));
	else if (parse_tree->type & PIPE)
	{
		make_pipes(pipes, parse_tree->right);
		make_pipes(pipes, parse_tree->left);
	}
	else if (parse_tree->type & (t_token_type) REDIR_TYPE)
		make_pipes(pipes, parse_tree->left);
}
