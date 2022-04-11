/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:36:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 12:40:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "redirection.h"
#include <stddef.h>

void	make_pipes(t_pipes **pipes, t_parse_tree *p_tree)
{
	if (!p_tree)
		return ;
	if (p_tree->type & (AND | OR))
		add_pipes(pipes, init_pipes(NULL, copy_redir(p_tree->redir), p_tree));
	if (p_tree->type & WORD)
		add_pipes(pipes, init_pipes(convert_token_to_dptr(p_tree->token), \
									copy_redir(p_tree->redir), NULL));
	else if (p_tree->type & PIPE)
	{
		make_pipes(pipes, p_tree->right);
		make_pipes(pipes, p_tree->left);
	}
	else if (p_tree->type & (t_token_type) REDIR_TYPE)
		make_pipes(pipes, p_tree->left);
}
