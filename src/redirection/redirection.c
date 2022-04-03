/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 17:38:39 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include "terminal.h"

static t_redir	*init_redir(void)
{
	t_redir	*ret;

	ret = ft_malloc(sizeof(t_redir), 1);
	ret->in = STDIN_FILENO;
	ret->out = STDOUT_FILENO;
	ret->err = NULL;
	ret->err_target = NULL;
	return (ret);
}

static void	inherit_fd(t_redir *curr_redir, t_redir *old_redir)
{
	if (!old_redir)
		return ;
	curr_redir->in = old_redir->in;
	curr_redir->out = old_redir->out;
}

static t_redir_result	perform_redirection(
	t_parse_tree *parse_tree, t_redir *old_redir, t_context *context
)
{
	t_redir	*curr_redir;

	parse_tree->redir = init_redir();
	inherit_fd(curr_redir, old_redir);
	if (get_redir_in(parse_tree, context) == REDIR_ERR)
		return (REDIR_ERR);
	get_redir_out(parse_tree);
	return (REDIR_SUCCESS);
}

static t_redir_result	go_side_node(
	t_parse_tree *parse_tree, t_move_direction dir, t_context *context
)
{
	t_redir	*old_redir;

	old_redir = NULL;
	if (parse_tree->redir)
		old_redir = parse_tree->redir;
	if (dir == LEFT)
		parse_tree = parse_tree->left;
	else
		parse_tree = parse_tree->right;
	if (parse_tree)
		return (redirection(parse_tree, old_redir, context));
	return (REDIR_SUCCESS);
}

t_redir_result	redirection(
	t_parse_tree *parse_tree, t_redir *redir, t_context *context
)
{
	if (!parse_tree)
		return (REDIR_SUCCESS);
	if (perform_redirection(parse_tree, redir, context) == REDIR_ERR)
		return (REDIR_ERR);
	if (go_side_node(parse_tree, LEFT, context) == REDIR_ERR)
		return (REDIR_ERR);
	if (!(parse_tree->type & REDIR_TYPE))
	{
		if (go_side_node(parse_tree, RIGHT, context) == REDIR_ERR)
			return (REDIR_ERR);
	}
	return (REDIR_SUCCESS);
}
