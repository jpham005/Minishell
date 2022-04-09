/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:58:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 22:46:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static void	set_pipe_fd(t_pipes *pipes, int pipefd[2], int in)
{
	int	status;

	status = 0;
	if (pipes->redir->in == STDIN_FILENO)
		status |= !ft_dup2(in, STDIN_FILENO);
	if (pipes->redir->out == STDOUT_FILENO)
		status |= !ft_dup2(pipefd[1], STDOUT_FILENO);
	if (status)
		ft_exit(EXIT_FATAL);
}

static void	execute_middle(
	t_pipes *pipes, t_context *context, t_pid_list **pids, int *in
)
{
	int	pipefd[2];

	while (pipes->next)
	{
		set_sig_handler_parent(pipes->cmd[0]);
		add_pid_list(pids, ft_fork());
		if ((*pids)->pid == -1)
		{
			wait_pid_list(*pids);
			ft_exit(EXIT_FATAL);
		}
		if (!((*pids)->pid))
		{
			set_pipe_fd(pipes, pipefd, in);
			execute_child(pipes, context);
		}
		ft_close(pipefd[1]);
		ft_close(in);
		in = pipefd[0];
		pipes = pipes->next;
	}
}

static void	execute_end(
	t_pipes *pipes, t_context *context, t_pid_list **pids, int in
)
{
	set_sig_handler_parent(pipes->cmd[0]);
	add_pid_list(pids, ft_fork());
	if ((*pids)->pid == -1)
	{
		wait_pid_list(*pids);
		ft_exit(EXIT_FATAL);
	}
	if (!((*pids)->pid))
	{
		if (!ft_dup2(in, STDIN_FILENO))
			ft_exit(EXIT_FATAL);
		ft_close(in);
		execute_child(pipes, context);
	}
	ft_close(in);
}

void	execute_pipeline(t_pipes *pipes, t_context *context)
{
	t_pid_list	*pids;
	int			in;

	pids = NULL;
	in = STDIN_FILENO;
	execute_middle(pipes, context, &pids, in);
	execute_end(pipes, context, &pids, in);
	context->exit_status = get_exit_status(wait_pid_list(pids));
}
