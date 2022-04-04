/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:36:00 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 22:20:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <stdlib.h>

void	execute_pipeline(t_parse_tree *parse_tree, t_context *context)
{
	int		stat;

	if (check_redir_err(parse_tree->redir) \
		|| !set_in_out(parse_tree->redir->in, parse_tree->redir->out))
		exit(1);
	if (try_exec_built_in(parse_tree, context))
		exit(context->exit_status);
	execute_child(parse_tree, context);
}
