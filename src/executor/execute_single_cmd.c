/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:14:38 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 22:39:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_single_cmd(t_parse_tree *parse_tree, t_context *context)
{
	t_cmd_type	type;

	type = get_cmd_type(parse_tree->token->data);
	if (type != NON_BUILT_IN)
		context->exit_status = exec_built_in(type, parse_tree, context);
}
