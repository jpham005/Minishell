/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:05:59 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 12:37:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "terminal.h"

t_exit_status	set_execute_state(t_pipes *pipes, int is_parent)
{
	if (is_parent)
		set_sig_handler_parent(pipes);
	else
		set_sig_handler_child();
	if ((check_redir_err(pipes->redir) == REDIR_ERR) \
		|| set_in_out(pipes->redir->in, pipes->redir->out) == REDIR_ERR)
		return (EXIT_REDIR_ERR);
	return (EXIT_SUCCESS);
}

static void	execute_single_cmd(t_pipes *pipes, t_context *context)
{
	t_cmd_type	type;

	type = get_cmd_type(pipes);
	if ((type != NON_BUILT_IN) \
		&& (set_execute_state(pipes, 1) == EXIT_REDIR_ERR))
	{
		context->exit_status = EXIT_REDIR_ERR;
		return ;
	}
	if (type == NON_BUILT_IN)
	{
		execute_pipeline(pipes, context);
		return ;
	}
	if (type == LOGICAL)
		context->exit_status = execute_logical(pipes, context);
	else
		context->exit_status = execute_built_in(type, pipes, context);
	restore_in_out(context);
}

void	execute_pipes(t_pipes *pipes, t_context *context)
{
	if (!pipes->next)
		execute_single_cmd(pipes, context);
	else
		execute_pipeline(pipes, context);
}
