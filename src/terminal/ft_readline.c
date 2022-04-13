/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:20:16 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 13:55:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "readline.h"

t_context	*make_context_static(t_context *context)
{
	static t_context	*ret;

	if (context)
		ret = context;
	return (ret);
}

static void	set_term_readline(t_context *context)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_int_handler_readline);
	tcsetattr(context->std_fd[2], TCSANOW, &(context->term_state.rl_term));
}

static void	set_term_default(t_context *context)
{
	set_sig_handler_default();
	tcsetattr(context->std_fd[2], TCSANOW, &(context->term_state.default_term));
}

static void	set_readline_variable(void)
{
	rl_catch_signals = 0;
	rl_outstream = stderr;
}

char	*ft_readline(t_context *context, char *str)
{
	char		*ret;

	set_readline_variable();
	make_context_static(context);
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
