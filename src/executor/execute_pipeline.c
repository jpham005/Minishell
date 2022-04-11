/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:58:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:32:47 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static void	prepare_execute(int *pipefd, t_pipes *pipes, t_pid_list **pids)
{
	set_sig_handler_parent(pipes);
	if (pipefd && (init_pipe(pipefd) == EXIT_FATAL))
		wait_exit_fatal(*pids);
	add_pid_list(pids, ft_fork());
	if ((*pids)->pid == -1)
		wait_exit_fatal(*pids);
}

static void	execute_end(
	t_pipes *pipes, t_context *context, t_pid_list **pids, int in
)
{
	prepare_execute(NULL, pipes, pids);
	if (!(*pids)->pid)
	{
		if (!ft_dup2(in, STDIN_FILENO))
			ft_exit(EXIT_FATAL);
		ft_close(in);
		// if (pipes->parse_tree)
		// 	execute_logical(pipes, context);
		// else
		// {
			set_in_out(pipes->redir->in, pipes->redir->out);
			execute_child(pipes, context);
		// }
	}
	ft_close(in);
	close_redir(pipes->redir);
}

static void	execute_lines(
	t_pipes *pipes, t_context *context, t_pid_list **pids
)
{
	int	pipefd[2];
	int	in;

	in = STDIN_FILENO;
	while (pipes->next)
	{
		prepare_execute(pipefd, pipes, pids);
		if (!((*pids)->pid))
		{
			set_pipe_fd(pipes, pipefd, in);
			// if (pipes->parse_tree)
			// 	execute_logical(pipes, context);
			// else
			// {
				set_in_out(pipes->redir->in, pipes->redir->out);
				execute_child(pipes, context);
			// }
		}
		set_next_in(pipefd, &in);
		close_redir(pipes->redir);
		pipes = pipes->next;
		pids = &((*pids)->next);
	}
	execute_end(pipes, context, pids, in);
}

void	execute_pipeline(t_pipes *pipes, t_context *context)
{
	t_pid_list	*pids;

	pids = NULL;
	execute_lines(pipes, context, &pids);
	context->exit_status = get_exit_status(wait_pid_list(pids));
	clear_pid_list(&pids);
}
