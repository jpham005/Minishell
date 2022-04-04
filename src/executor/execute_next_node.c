/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_next_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:56:58 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 22:52:24 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <stdlib.h>

static t_parse_tree	*get_next_node(
	t_parse_tree *parse_tree, t_move_direction dir
)
{
	if (dir == LEFT)
		return (parse_tree->left);
	return (parse_tree->right);
}

static void	set_pipe_fd(
	t_parse_tree *parse_tree, int in, int out, t_move_direction dir
)
{
	if (dir == LEFT)
	{
		if (parse_tree->redir->in == STDIN_FILENO)
			
	}
	if (parse_tree->redir->in == STDIN_FILENO)
		parse_tree->redir->in = in;
	if (parse_tree->redir->out == STDOUT_FILENO)
		parse_tree->redir->out = out;
}

static void	handle_pipe(t_parse_tree *parse_tree, t_context *context, \
									t_pid_list **pid_list, t_move_direction dir)
{
	pid_t			pid;
	int				pipeline[2];
	t_parse_tree	*next;

	next = get_next_node(parse_tree, dir);
	if (next->type == PIPE)
	{
		executor(next, context, pid_list);
		return ;
	}
	if (!ft_pipe(pipeline))
		exit(1);
	pid = ft_fork();
	if (!pid)
	{
		set_pipe_fd(next, STDIN_FILENO, pipeline[1], dir);
		ft_close(pipeline[0]);
		executor(next, context, pid_list);
	}
	add_pid_list(pid_list, pid);
	set_pipe_fd(parse_tree, pipeline[0], STDOUT_FILENO, dir);
	ft_close(pipeline[1]);
	return ;
}

void	execute_next_node(t_parse_tree *parse_tree, t_context *context, \
									t_pid_list **pid_list, t_move_direction dir)
{
	if (parse_tree->type == PIPE)
		handle_pipe(parse_tree, context, pid_list, dir);
}
