/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:07:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/01 21:27:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static void	handle_redir_in(t_parse_tree *parse_tree)
{
	if (check_valid_redir_target(parse_tree))
			set_redir_err(parse_tree, parse_tree->original_str, \
															TOKEN_ERR_MESSAGE);
	parse_tree->redir->in = open(parse_tree->token->data, O_RDONLY);
	if (parse_tree->redir->in == -1)
		set_redir_err(parse_tree, parse_tree->token->data, strerror(errno));
}

void	get_redir_in(t_parse_tree *parse_tree, t_context *context)
{
	if (parse_tree->type & REDIR_IN)
		handle_redir_in(parse_tree);
	else if (parse_tree->type & REDIR_HEREDOC)
		handle_redir_heredoc(parse_tree, context);
}
