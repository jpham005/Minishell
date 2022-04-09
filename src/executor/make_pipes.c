/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:36:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 16:05:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "redirection.h"

void	make_pipes(t_pipes **pipes, t_parse_tree *parse_tree)
{
	if (!parse_tree || (parse_tree->type & (AND | OR)))
		return ;
	if (parse_tree->type & WORD)
		add_pipes(pipes, init_pipes(convert_token_to_dptr(parse_tree->token), \
									copy_redir(parse_tree->redir)));
	else if (parse_tree->type & PIPE)
	{
		make_pipes(pipes, parse_tree->right);
		make_pipes(pipes, parse_tree->left);
	}
}
