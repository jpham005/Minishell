/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:58:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/10 11:27:31 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static t_exit_status	init_pipe(int pipefd[2])
{
	if (!ft_pipe(pipefd))
		return (EXIT_FATAL);
	return (EXIT_SUCCESS);
}

static void	execute_middle(
	t_pipes **pipes, t_context *context, t_pid_list **pids, int *in
)
{
	int	pipefd[2];

	while ((*pipes)->next)
	{
		set_sig_handler_parent((*pipes)->cmd[0]);
		if (init_pipe(pipefd) == EXIT_FATAL)
			wait_exit_fatal(*pids);
		add_pid_list(pids, ft_fork());
		if ((*pids)->pid == -1)
			wait_exit_fatal(*pids);
		if (!((*pids)->pid))
		{
			set_pipe_fd(*pipes, pipefd, *in);
			execute_child(*pipes, context);
			ft_putstr_fd("not exited\n", 2);
		}
		set_next_in(pipefd, in);
		*pipes = (*pipes)->next;
		pids = &((*pids)->next);
	}
}

static void	execute_end(
	t_pipes *pipes, t_context *context, t_pid_list **pids, int in
)
{
	t_pid_list	*curr;

	set_sig_handler_parent(pipes->cmd[0]);
	add_pid_list(pids, ft_fork());
	curr = get_last_pid_list(*pids);
	if (curr->pid == -1)
	{
		wait_pid_list(*pids);
		ft_exit(EXIT_FATAL);
	}
	if (!curr->pid)
	{
		if ((pipes->redir->in == STDIN_FILENO) && !ft_dup2(in, STDIN_FILENO))
			ft_exit(EXIT_FATAL);
		ft_close(in);
		execute_child(pipes, context);
		ft_putstr_fd("not exited\n", 2);
	}
	ft_close(in);
}

void	execute_pipeline(t_pipes *pipes, t_context *context)
{
	t_pipes		**pipes_cp;
	t_pid_list	*pids;
	int			in;

	pipes_cp = &pipes;
	pids = NULL;
	in = STDIN_FILENO;
	execute_middle(pipes_cp, context, &pids, &in);
	execute_end(*pipes_cp, context, &pids, in);
	context->exit_status = get_exit_status(wait_pid_list(pids));
	clear_pid_list(&pids);
}
