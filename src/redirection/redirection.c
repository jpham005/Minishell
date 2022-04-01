/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/01 22:01:13 by jaham            ###   ########.fr       */
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

static void	perform_redirection(
	t_parse_tree *parse_tree, t_redir *old_redir, t_context *context
)
{
	t_redir	*curr_redir;

	parse_tree->redir = init_redir();
	inherit_fd(curr_redir, old_redir);
	get_redir_in(parse_tree, context);
	// get_redir_out(parse_tree);
}

static void	go_side_node(
	t_parse_tree *parse_tree, t_move_direction dir, t_context *context
)
{
	if (dir == LEFT)
		parse_tree = parse_tree->left;
	else
		parse_tree = parse_tree->right;
	if (parse_tree)
		redirection(parse_tree, parse_tree->redir, context);
}

void	redirection(
	t_parse_tree *parse_tree, t_redir *redir, t_context *context
)
{
	if (!parse_tree)
		return ;
	perform_redirection(parse_tree, redir, context);
	go_side_node(parse_tree, LEFT, context);
	if (!(parse_tree->type & REDIR_TYPE))
		go_side_node(parse_tree, RIGHT, context);
}
