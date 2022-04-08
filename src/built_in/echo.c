/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 10:10:54 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

static int	write_argv(const char **argv)
{
	while (*argv)
	{
		if (ft_putstr_fd(*argv, STDOUT_FILENO) == -1)
			return (1);
		argv++;
		if (*argv && ft_putstr_fd(" ", STDOUT_FILENO) == -1)
			return (1);
	}
	return (0);
}

static int	perform_echo(const char **argv, int n_op)
{
	if (write_argv(argv))
		return (1);
	if (!n_op && (ft_putstr_fd("\n", STDOUT_FILENO) == -1))
		return (1);
	return (0);
}

static int	is_n_op(const char *argv)
{
	if (*(argv++) != '-')
		return (0);
	while (*argv && (*argv == 'n'))
		argv++;
	return (*argv == '\0');
}

static int	get_n_op(const char **argv, size_t *i)
{
	while (argv[*i] && is_n_op(argv[*i]))
		(*i)++;
	return (*i != 1);
}

int	echo(t_context *context, const char **argv)
{
	int		n_op;
	size_t	i;

	if (!context)
		return (1);
	if (!argv[1])
		return (ft_putstr_fd("\n", STDOUT_FILENO) == -1);
	i = 1;
	n_op = get_n_op(argv, &i);
	return (perform_echo(argv + i, n_op));
}
