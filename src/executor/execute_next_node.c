/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_next_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:56:58 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 13:47:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

t_parse_tree	*get_next_node(t_parse_tree *parse_tree, t_move_direction dir)
{
	if (dir == LEFT)
		return (parse_tree->left);
	return (parse_tree->right);
}

static void	handle_redirection(
	t_parse_tree *parse_tree, t_context *context, t_pid_list **pid_list
)
{
	set_pipe_fd(parse_tree, parse_tree->redir->in, \
												parse_tree->redir->out, LEFT);
	executor(parse_tree->left, context, pid_list);
}

static void	switch_fd(t_context *context, int backup_fd[2], t_redir *redir)
{
	backup_fd[0] = context->std_fd[0];
	backup_fd[1] = context->std_fd[1];
	context->std_fd[0] = redir->in;
	context->std_fd[1] = redir->out;
}
#include <stdio.h>
static void	handle_logical(
	t_parse_tree *parse_tree, t_context *context, t_pid_list **pid_list
)
{
	int	backup_fd[2];

	switch_fd(context, backup_fd, parse_tree->redir);
	set_in_out(parse_tree->redir->in, parse_tree->redir->out);
	executor(parse_tree->left, context, pid_list);
	if ((parse_tree->type == AND) && !context->exit_status)
		executor(parse_tree->right, context, pid_list);
	if ((parse_tree->type == OR) && context->exit_status)
		executor(parse_tree->right, context, pid_list);
	ft_close(parse_tree->right->redir->in);
	ft_close(parse_tree->right->redir->out);
	context->std_fd[0] = backup_fd[0];
	context->std_fd[1] = backup_fd[1];
}

void	execute_next_node(
	t_parse_tree *parse_tree, t_context *context, t_pid_list **pid_list
)
{
	if (parse_tree->type & PIPE)
		handle_pipe(parse_tree, context, pid_list);
	else if (parse_tree->type & REDIRECTION_META)
		handle_redirection(parse_tree, context, pid_list);
	else if (parse_tree->type & (AND | OR))
		handle_logical(parse_tree, context, pid_list);
}
