/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_logical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:29:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:20:34 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	execute_logical(t_pipes *pipes, t_context *context)
{
	executor(pipes->parse_tree->left, context);
	if ((pipes->parse_tree->type == AND) && !context->exit_status)
		executor(pipes->parse_tree->right, context);
	if ((pipes->parse_tree->type == OR) && context->exit_status)
		executor(pipes->parse_tree->right, context);
	return (context->exit_status);
}
