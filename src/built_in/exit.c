/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:25:58 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 14:37:45 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_exit(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		ft_putstr_fd("exit\n", STDERR_FILENO);
}

static int	check_valid(const char **argv)
{
	if (!argv[1])
		return (EXIT_NO_ARG);
	if (!ft_isnumstr(argv[1]))
		return (EXIT_NON_NUMERIC);
	if (argv[2])
		return (EXIT_TOO_MANY_ARG);
	return (EXIT_NUMERIC);
}

static void	exit_with_message(int status)
{
	print_exit();
	exit(status);
}

static void	print_non_numeric_err_message(const char *str)
{
	print_exit();
	ft_putstr_fd(SHELL_NAME EXIT_CMD, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(EXIT_NON_NUMERIC_ERR_MESSAGE, STDERR_FILENO);
}

int	built_in_exit(t_context *context, const char **argv)
{
	int	state;

	state = check_valid(argv);
	if (state & EXIT_NO_ARG)
		exit_with_message(context->exit_status);
	if (state & EXIT_NON_NUMERIC)
	{
		print_non_numeric_err_message(argv[1]);
		exit(255);
	}
	if (state & EXIT_TOO_MANY_ARG)
	{
		print_exit();
		ft_putstr_fd(SHELL_NAME EXIT_CMD EXIT_TOO_MANY_ARG_ERR_MESSAGE, 2);
		return (1);
	}
	if (state & EXIT_NUMERIC)
		exit_with_message(ft_atoi(argv[1]));
	return (0);
}
