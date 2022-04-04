/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:14:38 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 22:18:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

void	execute_single_cmd(t_parse_tree *parse_tree, t_context *context)
{
	pid_t	pid;
	int		stat;

	if (check_redir_err(parse_tree->redir) \
		|| !set_in_out(parse_tree->redir->in, parse_tree->redir->out))
	{
		context->exit_status = 1;
		return ;
	}
	if (try_exec_built_in(parse_tree, context) && restore_in_out(context))
		return ;
	pid = ft_fork();
	if (!pid)
		execute_child(parse_tree, context);
	else if (!ft_waitpid(pid, &stat, 0))
		context->exit_status = 1;
	context->exit_status = get_exit_status(stat);
	restore_in_out(context);
}
