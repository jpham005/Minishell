/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:07:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 09:14:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static void	handle_redir_in(t_parse_tree *p_tree)
{
	if (!check_valid_redir_target(p_tree))
	{
		set_redir_err(p_tree, p_tree->right->original_str, TOKEN_ERR_MESSAGE);
		return ;
	}
	p_tree->redir->in = open(p_tree->right->token->data, O_RDONLY);
	if (p_tree->redir->in == -1)
		set_redir_err(p_tree, p_tree->right->token->data, strerror(errno));
}

static void	handle_redir_heredoc(t_parse_tree *parse_tree)
{
	parse_tree->redir->in = parse_tree->token->redir->in;
}

t_redir_result	get_redir_in(t_parse_tree *parse_tree)
{
	if (is_multiple_redir(parse_tree, REDIR_INS))
		ft_close(parse_tree->redir->in);
	if (parse_tree->type & REDIR_IN)
		handle_redir_in(parse_tree);
	else if (parse_tree->type & REDIR_HEREDOC)
		handle_redir_heredoc(parse_tree);
	return (REDIR_SUCCESS);
}
