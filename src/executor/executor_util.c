/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:42:10 by jaham             #+#    #+#             */
/*   Updated: 2022/04/10 09:53:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static const char * const	*get_built_in_types(void)
{
	static const char * const	built_in_types[] = {
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

t_cmd_type	get_cmd_type(const char *cmd)
{
	const char * const	*built_in = get_built_in_types();
	size_t		i;

	i = 0;
	while (built_in[i] && ft_strncmp(cmd, built_in[i], ft_strlen(cmd) + 1))
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
	ft_putstr_fd(":", STDERR_FILENO);
	ft_putstr_fd(redir->err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_REDIR_ERR);
}
