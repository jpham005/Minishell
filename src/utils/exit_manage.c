/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:15:53 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 09:52:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

void	write_error(const char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}

static void	print_exit(void)
{
	ft_putstr_fd("\033[1A", STDERR_FILENO);
	ft_putstr_fd("\033[12C", STDERR_FILENO);
	ft_putstr_fd("exit\n", STDERR_FILENO);
}

void	exit_with_condition(t_exit_condition condition, t_context *context)
{
	if (condition & END_TERM)
	{
		print_exit();
		ft_exit(context->exit_status);
	}
	if (condition & ARG_ERR)
		write_error(ARG_ERR_MESSAGE);
	else if (condition & DEFAULT_FD_ERR)
		write_error(DEFAULT_FD_ERR_MESSAGE);
	else if (condition & PRINT_INTRO_ERR)
		write_error(PRT_INTRO_ERR_MESSAGE);
	ft_exit(1);
}
