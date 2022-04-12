/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:42:10 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 12:37:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "terminal.h"
#include <stdlib.h>

static const char*const	*get_built_in_types(void)
{
	static const char *const	built_in_types[] = {
		"cd",
		"echo",
		"env",
		"exit",
		"export",
		"pwd",
		"unset",
		NULL
	};

	return (built_in_types);
}

t_cmd_type	get_cmd_type(t_pipes *pipes)
{
	const char*const	*built_in = get_built_in_types();
	size_t				i;

	if (pipes->parse_tree)
		return (LOGICAL);
	if (!pipes->cmd[0])
		return (NON_BUILT_IN);
	i = 0;
	while (built_in[i] && !ft_iseq(pipes->cmd[0], built_in[i]))
		++i;
	return (i);
}

int	get_exit_status(int stat)
{
	if (ft_wifexited(stat))
		return (ft_wexitstatus(stat));
	if (ft_wifsignaled(stat))
		return (ft_wtermsig(stat) + EXIT_SIGNAL);
	if (ft_wifstopped(stat))
		return (STOP_SIGNAL + EXIT_SIGNAL);
	return (CONTINUE_SIGNAL + EXIT_SIGNAL);
}

int	check_redir_err(t_redir *redir)
{
	if (!redir->err)
		return (EXIT_SUCCESS);
	ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
	ft_putstr_fd(redir->err_target, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(redir->err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_REDIR_ERR);
}

void	exit_with_msg(char *s1, char *s2, int status)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(s2, STDERR_FILENO);
	if (!ft_strchr(s2, '\n'))
		ft_putstr_fd("\n", STDERR_FILENO);
	exit(status);
}
