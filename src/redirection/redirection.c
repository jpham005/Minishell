/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:51 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 17:20:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "libft.h"

static t_redir	*init_redir(void)
{
	t_redir	*ret;

	ret = ft_malloc(sizeof(t_redir), 1);
	ret->in = STDIN_FILENO;
	ret->out = STDOUT_FILENO;
	ret->err = NULL;
	ret->target = NULL;
}

static void	inherit_fd(t_redir *curr_redir, t_redir *old_redir)
{
	if (!old_redir)
		return ;
	curr_redir->in = old_redir->in;
	curr_redir->out = old_redir->out;
}

static void	perform_redirection(t_parse_tree *parse_tree, t_redir *old_redir)
{
	t_redir	*curr_redir;

	parse_tree->redir = init_redir();
	inherit_fd(curr_redir, old_redir);
	get_redir_in(parse_tree);
	get_redir_out(parse_tree);
}

void	redirection(t_parse_tree *parse_tree, t_redir *redir)
{
	if (!parse_tree)
		return ;
	perform_redirection(parse_tree, redir);
	go_side_node(parse_tree, LEFT);
	go_side_node(parse_tree, RIGHT);
}
