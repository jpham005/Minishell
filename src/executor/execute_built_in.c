/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:03:40 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 17:31:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "executor.h"
#include "libft.h"

static void	set_built_in_fptr(
	int (*built_in[7]) (t_context *context, const char **argv)
)
{
	built_in[0] = cd;
	built_in[1] = echo;
	built_in[2] = env;
	built_in[3] = built_in_exit;
	built_in[4] = export;
	built_in[5] = pwd;
	built_in[6] = unset;
}

int	exec_built_in(t_cmd_type type, t_parse_tree *parse_tree, t_context *context)
{
	char	**args;
	int		(*built_in[7])(t_context *context, const char **argv);
	int		ret;

	set_in_out(parse_tree->redir->in, parse_tree->redir->out);
	args = convert_token_to_dptr(parse_tree->token);
	set_built_in_fptr(built_in);
	ret = built_in[type](context, (const char **) args);
	free_c_dptr(&args);
	restore_in_out(context);
	return (ret);
}

int	try_exec_built_in(t_parse_tree *parse_tree, t_context *context)
{
	t_cmd_type	type;

	type = get_cmd_type(parse_tree->token->data);
	if (type == NON_BUILT_IN)
		return (0);
	context->exit_status = exec_built_in(type, parse_tree, context);
	return (1);
}
