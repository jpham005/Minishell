/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:25:58 by jaham             #+#    #+#             */
/*   Updated: 2022/03/01 12:47:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("exit\n");
	exit(status);
}

static void	print_non_numeric_err_message(const char *str)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd(SHELL_NAME EXIT_CMD, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(EXIT_NON_NUMERIC_ERR_MESSAGE, 2);
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
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd(SHELL_NAME EXIT_CMD EXIT_TOO_MANY_ARG_ERR_MESSAGE, 2);
		return (1);
	}
	if (state & EXIT_NUMERIC)
		exit_with_message(ft_atoi(argv[1]));
	return (0);
}
