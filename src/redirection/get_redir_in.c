/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:07:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 17:28:21 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static void	handle_redir_in(t_parse_tree *p_tree)
{
	if (check_valid_redir_target(p_tree))
	{
		set_redir_err(p_tree, p_tree->right->original_str, TOKEN_ERR_MESSAGE);
		return ;
	}
	p_tree->redir->in = open(p_tree->right->token->data, O_RDONLY);
	if (p_tree->redir->in == -1)
		set_redir_err(p_tree, p_tree->right->token->data, strerror(errno));
}

t_redir_result	get_redir_in(t_parse_tree *parse_tree, t_context *context)
{
	if (parse_tree->type & REDIR_IN)
		handle_redir_in(parse_tree);
	else if (parse_tree->type & REDIR_HEREDOC)
	{
		if (handle_redir_heredoc(parse_tree, context) == REDIR_ERR)
			return (REDIR_ERR);
	}
	return (REDIR_SUCCESS);
}
