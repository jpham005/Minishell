/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:58:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 12:31:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "terminal.h"
#include <stdlib.h>

static void	prepare_pipeline(int pipefd[2], t_pipes *pipes, t_pid_list **pids)
{
	if (pipes->next && (init_pipe(pipefd) == EXIT_FATAL))
		wait_exit_fatal(*pids);
	add_pid_list(pids, ft_fork());
	if ((*pids)->pid == -1)
		wait_exit_fatal(*pids);
}

static void	execute_lines(
	t_pipes *pipes, t_context *context, t_pid_list **pids
)
{
	int	pipefd[2];
	int	in;

	in = STDIN_FILENO;
	while (pipes)
	{
		prepare_pipeline(pipefd, pipes, pids);
		if (!((*pids)->pid))
		{
			set_pipe_fd(pipes, pipefd, in);
			if (set_execute_state(pipes, 0) == REDIR_ERR)
				exit(REDIR_ERR);
			execute_child(pipes, context);
		}
		set_next_in(pipefd, &in);
		close_redir(pipes->redir);
		pipes = pipes->next;
		pids = &((*pids)->next);
	}
}

void	execute_pipeline(t_pipes *pipes, t_context *context)
{
	t_pid_list	*pids;

	pids = NULL;
	execute_lines(pipes, context, &pids);
	context->exit_status = get_exit_status(wait_pid_list(pids));
	clear_pid_list(&pids);
}
