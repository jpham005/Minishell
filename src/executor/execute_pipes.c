/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:05:59 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 17:24:10 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static t_exit_status	set_execute_state(t_pipes *pipes)
{
	set_sig_handler_parent(pipes->cmd[0]);
	if (check_redir_err(pipes->redir) | set_in_out(pipes->redir))
		return (EXIT_REDIR_ERR);
	return (EXIT_SUCCESS);
}

static void	execute_pipeline(t_pipes *pipes, t_context *context)
{
	t_pid_list	*pids;

	pids = NULL;
	while (pipes)
	{
		add_pid_list(&pids, ft_fork());
		if (pids->pid == -1)
			
		if (!pids->pid)
			execute_child();
	}
}

static void	execute_single_cmd(t_pipes *pipes, t_context *context)
{
	t_cmd_type	type;

	if (set_execute_state(pipes) == EXIT_REDIR_ERR)
	{
		context->exit_status = EXIT_REDIR_ERR;
		return ;
	}
	type = get_cmd_type(pipes->cmd[0]);
	if (type == NON_BUILT_IN)
		execute_pipeline(pipes, context);
	else
		exec_built_in(pipes, context);
	restore_in_out(context);
}

void	execute_pipes(t_pipes *pipes, t_context *context)
{
	if (!pipes->next)
		execute_single_cmd(pipes, context);
	execute_pipeline(pipes, context);
}
