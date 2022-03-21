/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:01:21 by jaham             #+#    #+#             */
/*   Updated: 2022/03/07 18:00:03 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <signal.h>

void	set_sig_handler_parent(char **cmd)
{
	if (cmd && !ft_strncmp(cmd[0] + ft_strlen(cmd[0]) - 10, "/minishell", 11))
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
