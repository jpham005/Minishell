/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:01:21 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 18:53:42 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <signal.h>

void	set_sig_handler_parent(char *cmd)
{
	const size_t	cmd_len = ft_strlen(cmd);

	if (cmd \
		&& (cmd_len >= 10) \
		&& !ft_strncmp(cmd + ft_strlen(cmd) - 10, "/minishell", 11))
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, sig_int_handler_default);
		signal(SIGQUIT, sig_quit_handler);
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
