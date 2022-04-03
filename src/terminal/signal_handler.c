/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:08:08 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 15:10:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

void	sig_int_handler_default(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", 2);
}

void	sig_quit_handler(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr_fd(SIG_QUIT_MESSAGE, 2);
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		exit(2);
	}
}

void	sig_int_handler_readline(int sig)
{
	t_context	*context;

	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		context = make_context_static(NULL);
		context->exit_status = 1;
	}
}
