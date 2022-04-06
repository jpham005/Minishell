/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:15:50 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 13:55:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
void	set_pipe_fd(
	t_parse_tree *parse_tree, int in, int out, t_move_direction dir
)
{
	t_parse_tree	*next;
printf("set pipe fd %d %d %d %d\n", in, out, fcntl(in, F_GETFD), fcntl(out, F_GETFD));
	next = get_next_node(parse_tree, dir);
	if (next->redir->in == STDIN_FILENO)
	{
		ft_dup2(in, STDIN_FILENO);
		ft_close(in);
	}
	if (next->redir->out == STDOUT_FILENO)
	{
		ft_dup2(out, STDOUT_FILENO);
		ft_close(out);
	}
printf("end set pipe fd %d %d %d %d\n", in, out, fcntl(in, F_GETFD), fcntl(out, F_GETFD));
}

static void	close_all_redir(t_parse_tree *parse_tree)
{
	if (!parse_tree)
		return ;
	if (parse_tree->redir)
	{
		ft_close(parse_tree->redir->in);
		ft_close(parse_tree->redir->out);
	}
	close_all_redir(parse_tree->left);
	close_all_redir(parse_tree->right);
}

#include <stdio.h>
static void	handle_pipe_left(t_parse_tree *parse_tree, t_context *context, \
										t_pid_list **pid_list, int pipeline[2])
{
	pid_t	pid;

	set_pipe_fd(parse_tree, parse_tree->redir->in, pipeline[1], LEFT);
	if (parse_tree->left->type == PIPE)
	{
		handle_pipe(parse_tree->left, context, pid_list);
		return ;
	}
	pid = ft_fork();
	// printf("left forking %d\n", pid);
	if (!pid)
	{
		ft_close(pipeline[0]);
		// printf("left going %d %d\n", parse_tree->left->redir->in, parse_tree->left->redir->out);
		executor(parse_tree->left, context, pid_list);
		ft_exit(context->exit_status);
	}
	add_pid_list(pid_list, pid);
	ft_close(pipeline[1]);
	close_all_redir(parse_tree->left);
	restore_in_out(context);
	return ;
}

static void	handle_pipe_right(t_parse_tree *parse_tree, t_context *context, \
										t_pid_list **pid_list, int pipeline[2])
{
	pid_t	pid;

	set_pipe_fd(parse_tree, pipeline[0], parse_tree->redir->out, RIGHT);
	if (parse_tree->right->type == PIPE)
	{
		handle_pipe(parse_tree->right, context, pid_list);
		return ;
	}
	pid = ft_fork();
	// printf("right forking %d\n", pid);
	if (!pid)
	{
		// printf("going right addr %p\n", parse_tree->right);
		// printf("going right %d %d\n", parse_tree->right->redir->in, parse_tree->right->redir->out);
		executor(parse_tree->right, context, pid_list);
		ft_exit(context->exit_status);
	}
	add_pid_list(pid_list, pid);
	ft_close(pipeline[0]);
	ft_close(parse_tree->redir->in);
	ft_close(parse_tree->redir->out);
	close_all_redir(parse_tree->right);
	restore_in_out(context);
	return ;
}

void	handle_pipe(
	t_parse_tree *parse_tree, t_context *context, t_pid_list **pid_list
)
{
	int	pipeline[2];

	if (!ft_pipe(pipeline))
		ft_exit(1);
// printf("piping %d %d\n", pipeline[0], pipeline[1]);
	handle_pipe_left(parse_tree, context, pid_list, pipeline);
	handle_pipe_right(parse_tree, context, pid_list, pipeline);
}
