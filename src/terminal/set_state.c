/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:20:16 by jaham             #+#    #+#             */
/*   Updated: 2022/03/09 12:33:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <readline/readline.h>

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

	set_term_readline(context);
	if (!str)
		ret = readline(MINISHELL_WITH_COLOR);
	else
	{
		signal(SIGINT, heredoc_handler);
		ret = readline(str);
	}
	set_term_default(context);
	return (ret);
}
