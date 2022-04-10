/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:03:40 by jaham             #+#    #+#             */
/*   Updated: 2022/04/10 10:08:03 by jaham            ###   ########.fr       */
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

int	execute_built_in(t_cmd_type type, t_pipes *pipes, t_context *context)
{
	int		(*built_in[7])(t_context *context, const char **argv);

	set_built_in_fptr(built_in);
	return (built_in[type](context, (const char **) pipes->cmd));
}
