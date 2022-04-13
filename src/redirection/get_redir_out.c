/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:25:13 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 09:14:47 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static void	handle_redir_out(t_parse_tree *p_tree, t_token_type type)
{
	int	open_op;

	if (!check_valid_redir_target(p_tree))
	{
		set_redir_err(p_tree, p_tree->right->original_str, TOKEN_ERR_MESSAGE);
		return ;
	}
	open_op = O_WRONLY | O_CREAT;
	if (type & REDIR_OUT)
		open_op |= O_TRUNC;
	else
		open_op |= O_APPEND;
	p_tree->redir->out = open(p_tree->right->token->data, open_op, 0666);
	if (p_tree->redir->out == -1)
		set_redir_err(p_tree, p_tree->right->token->data, strerror(errno));
}

void	get_redir_out(t_parse_tree *parse_tree)
{
	if (is_multiple_redir(parse_tree, REDIR_OUTS))
		ft_close(parse_tree->redir->out);
	if (parse_tree->type & (REDIR_OUT | REDIR_APPEND))
		handle_redir_out(parse_tree, parse_tree->type);
}
