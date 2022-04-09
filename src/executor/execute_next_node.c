/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ next_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:05:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 22:43:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_next_node(t_parse_tree *parse_tree, t_context *context)
{
	executor(parse_tree->left, context);
	if ((parse_tree->type == AND) && (context->exit_status == EXIT_SUCCESS))
		executor(parse_tree->right, context);
	else if ((parse_tree->type == OR) && context->exit_status != EXIT_SUCCESS)
		executor(parse_tree->right, context);
}
