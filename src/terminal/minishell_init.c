/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:41:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 19:38:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "libft.h"
#include "terminal.h"

static void	update_shlvl(t_envp_list *envp)
{
	t_envp_list	*shlvl_list;
	int			shlvl;
	char		*new;

	shlvl_list = find_list_by_key(envp, "SHLVL");
	if (!shlvl_list)
	{
		update_envp_list(&envp, "SHLVL", "1");
		return ;
	}
	shlvl = ft_atoi(shlvl_list->value);
	shlvl++;
	new = ft_itoa(shlvl);
	update_envp_list(&envp, "SHLVL", new);
	ft_free((void **) &new);
}

void	shell_init(t_context *context, char **envp)
{
	t_term		term;

	context->std_fd[0] = ft_dup(STDIN_FILENO);
	context->std_fd[1] = ft_dup(STDOUT_FILENO);
	context->std_fd[2] = ft_dup(STDERR_FILENO);
	if (tcgetattr(STDERR_FILENO, &term))
		perror_exit("tcgetattr", 1);
	context->exit_status = 0;
	context->term_state.default_term = term;
	term.c_lflag &= ~ECHOCTL;
	context->term_state.rl_term = term;
	init_envp_list(&(context->envp), envp);
	update_shlvl(context->envp);
}
