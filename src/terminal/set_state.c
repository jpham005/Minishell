/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:20:16 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 14:48:01 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <readline/readline.h>

static t_context	*s_context;

void	sig_int_handler_readline(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		s_context->exit_status = 1;
	}
}

static void	set_term_readline(t_context *context)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_int_handler_readline);
	tcsetattr(context->std_fd[1], TCSANOW, &(context->term_state.rl_term));
}

static void	set_term_default(t_context *context)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	tcsetattr(context->std_fd[1], TCSANOW, &(context->term_state.default_term));
}

char	*ft_readline(t_context *context, char *str)
{
	char	*ret;

	s_context = context;
	set_term_readline(context);
	if (!str)
	{
		if (context->exit_status == 0)
			ret = readline(MINISHELL_WITH_COLOR);
		else
			ret = readline(MINISHELL_WITH_COLOR_ERR);
	}
	else
	{
		signal(SIGINT, heredoc_handler);
		ret = readline(str);
	}
	set_term_default(context);
	return (ret);
}
