/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:01:21 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:04:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <signal.h>

void	set_sig_handler_parent(t_pipes *pipes)
{
	if (pipes->parse_tree || !pipes->cmd[0] || (ft_strlen(pipes->cmd[0]) < 10) \
	|| !ft_iseq(pipes->cmd[0] + ft_strlen(pipes->cmd[0]) - 10, "/minishell"))
	{
		signal(SIGINT, sig_int_handler_default);
		signal(SIGQUIT, sig_quit_handler);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	set_sig_handler_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_sig_handler_default(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
