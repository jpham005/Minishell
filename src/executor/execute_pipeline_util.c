/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:53:38 by jaham             #+#    #+#             */
/*   Updated: 2022/04/10 10:10:27 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

void	set_pipe_fd(t_pipes *pipes, int pipefd[2], int in)
{
	int	status;

	status = 0;
	if (pipes->redir->in == STDIN_FILENO)
		status |= !ft_dup2(in, STDIN_FILENO);
	if (pipes->redir->out == STDOUT_FILENO)
		status |= !ft_dup2(pipefd[1], STDOUT_FILENO);
	ft_close(in);
	ft_close(pipefd[0]);
	ft_close(pipefd[1]);
	if (status)
		ft_exit(EXIT_FATAL);
}

void	wait_exit_fatal(t_pid_list *pids)
{
	wait_pid_list(pids);
	ft_exit(EXIT_FATAL);
}

void	set_next_in(int pipefd[2], int *in)
{
	ft_close(pipefd[1]);
	ft_close(*in);
	*in = pipefd[0];
}
