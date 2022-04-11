/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:53:38 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 13:03:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <stdlib.h>

void	set_pipe_fd(t_pipes *pipes, int pipefd[2], int in)
{
	int	status;

	status = 0;
	if (pipes->parse_tree || pipes->redir->in == STDIN_FILENO)
		status |= !ft_dup2(in, STDIN_FILENO);
	ft_close(in);
	if (status && !(pipes->next))
		exit(EXIT_FATAL);
	if (!pipes->next)
		return ;
	if (pipes->parse_tree || pipes->redir->out == STDOUT_FILENO)
		status |= !ft_dup2(pipefd[1], STDOUT_FILENO);
	ft_close(pipefd[0]);
	ft_close(pipefd[1]);
	if (status)
		exit(EXIT_FATAL);
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

t_exit_status	init_pipe(int pipefd[2])
{
	if (!ft_pipe(pipefd))
		return (EXIT_FATAL);
	return (EXIT_SUCCESS);
}

void	close_redir(t_redir *redir)
{
	ft_close(redir->in);
	ft_close(redir->out);
}
