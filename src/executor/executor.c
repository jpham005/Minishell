/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:37:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 22:24:16 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <stdio.h>
static void	execute_cmd(t_parse_tree *parse_tree, t_context *context)
{
	if (parse_tree->up && (parse_tree->up->type & PIPE))
		execute_pipeline(parse_tree, context);
	else
		execute_single_cmd(parse_tree, context);
}

void	executor(
	t_parse_tree *parse_tree, t_context *context, t_pid_list **pid_list
)
{
	if (!parse_tree)
		return ;
	if (parse_tree->type == WORD)
	{
		printf("%d %d\n", parse_tree->redir->in, parse_tree->redir->out);
		set_sig_handler_parent(parse_tree->token->data);
		update_envp_list(&(context->envp), "_", parse_tree->token->data);
			execute_cmd(parse_tree, context);
		set_sig_handler_default();
	}
	execute_next_node(parse_tree, context, pid_list, LEFT);
	execute_next_node(parse_tree, context, pid_list, RIGHT);
}
