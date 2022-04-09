/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:37:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 17:04:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"
#include "redirection.h"
#include <stddef.h>

void	executor(
	t_parse_tree *parse_tree, t_context *context
)
{
	t_pipes	*pipes;

	if (!parse_tree)
		return ;
	if (!(parse_tree->type & (WORD | PIPE)))
		execute_next_node(parse_tree, context);
	expander(parse_tree, context);
	redirection(parse_tree, NULL, context);
	pipes = NULL;
	make_pipes(&pipes, parse_tree);
	execute_pipes(pipes, context);
	set_sig_handler_default();
	clear_pipes(&pipes);
}
