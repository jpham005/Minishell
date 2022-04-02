/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:20:16 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 22:09:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <readline/readline.h>

t_context	*make_context_static(t_context *context)
{
	static t_context	*ret;

	if (context)
		ret = context;
	return (ret);
}

int	make_sigint_static(int n)
{
	static int	ret;

	if (n >= 0)
		ret = n;
	return (ret);
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
	char		*ret;

	rl_catch_signals = 0;
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
		make_sigint_static(0);
		signal(SIGINT, heredoc_handler);
		ret = readline(str);
	}
	set_term_default(context);
	return (ret);
}
