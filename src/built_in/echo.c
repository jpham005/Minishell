/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:39 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 03:40:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

static void	write_argv(const char **argv)
{
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		argv++;
		if (*argv)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
}

static int	perform_echo(const char **argv, int n_op)
{
	int	ret;

	write_argv(argv);
	if (!n_op)
		ret = ft_putstr_fd("\n", STDOUT_FILENO);
	return (ret == -1);
}

int	echo(t_context *context, const char **argv)
{
	int	ret;
	int	n_op;

	if (!context)
		return (1);
	if (!argv[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	n_op = !ft_strncmp(argv[1], "-n", 3);
	ret = perform_echo(argv, n_op);
	return (ret);
}
