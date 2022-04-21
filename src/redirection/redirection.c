/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 21:02:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include "t_move.h"

static t_redir	*inherit_redir(t_parse_tree *parse_tree, t_redir *old_redir)
{
	t_redir	*ret;

	ret = copy_redir(old_redir);
	if (parse_tree->up && (parse_tree->up->type & PIPE))
	{
		if (parse_tree->up->left == parse_tree)
			ret->out = STDOUT_FILENO;
		else
			ret->in = STDIN_FILENO;
	}
	return (ret);
}

static t_redir_result	perform_redirection(
	t_parse_tree *parse_tree, t_redir *old_redir
)
{
	parse_tree->redir = inherit_redir(parse_tree, old_redir);
	if (parse_tree->type & REDIR_INS)
		get_redir_in(parse_tree);
	if (parse_tree->type & REDIR_OUTS)
		get_redir_out(parse_tree);
	return (REDIR_SUCCESS);
}

static t_redir_result	go_side_node(
	t_parse_tree *parse_tree, t_move_direction dir, t_context *context
)
{
	t_redir	*old_redir;

	old_redir = parse_tree->redir;
	if (dir == LEFT)
		parse_tree = parse_tree->left;
	else
		parse_tree = parse_tree->right;
	return (redirection(parse_tree, old_redir, context));
}

t_redir_result	redirection(
	t_parse_tree *parse_tree, t_redir *redir, t_context *context
)
{
	if (!parse_tree)
		return (REDIR_SUCCESS);
	if (perform_redirection(parse_tree, redir) == REDIR_ERR)
		return (REDIR_ERR);
	if (parse_tree->type & (AND | OR))
		return (REDIR_SUCCESS);
	if (go_side_node(parse_tree, LEFT, context) == REDIR_ERR)
		return (REDIR_ERR);
	if (!(parse_tree->type & REDIR_TYPE) \
		&& go_side_node(parse_tree, RIGHT, context) == REDIR_ERR)
		return (REDIR_ERR);
	return (REDIR_SUCCESS);
}
