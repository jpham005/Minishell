/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:03:40 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 22:36:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "executor.h"
#include "libft.h"

int	exec_built_in(t_cmd_type type, t_parse_tree *parse_tree, t_context *context)
{
	char	**args;
	int		ret;

	int	(*built_in[])(t_context *context, const char **argv) = {
		cd, echo, env, built_in_exit, export, pwd, unset
	};

	args = convert_token_to_dptr(parse_tree->token);
	ret = built_in[type](context, (const char **) args);
	free_c_dptr(&args);
	return (ret);
}
