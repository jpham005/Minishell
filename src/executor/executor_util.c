/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:42:10 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 22:21:51 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <stddef.h>

static const char	**get_built_in_types(void)
{
	const static char	*built_in_types[] = {
		"cd",
		"echo",
		"env",
		"exit",
		"export",
		"pwd",
		"unset",
		NULL
	};

	return (built_in_types);
}

t_cmd_type	get_cmd_type(const char *cmd)
{
	const char * const	*built_in = get_built_in_types();
	size_t		i;

	i = 0;
	while (built_in[i] && ft_strncmp(cmd, built_in[i], ft_strlen(cmd) + 1))
		++i;
	return (i);
}
