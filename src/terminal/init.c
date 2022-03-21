/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:41:04 by jaham             #+#    #+#             */
/*   Updated: 2022/03/06 14:29:01 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	safe_free((void **) &new);
}

void	init_shell(t_context *context, const char **envp)
{
	t_term		term;

	context->std_fd[0] = ft_dup(0);
	context->std_fd[1] = ft_dup(1);
	context->std_fd[2] = ft_dup(2);
	if (tcgetattr(1, &term))
		perror_exit("tcgetattr", 1);
	context->exit_status = 0;
	context->term_state.default_term = term;
	term.c_lflag &= ~ECHOCTL;
	context->term_state.rl_term = term;
	init_envp_list(&(context->envp), (const char **) envp);
	update_shlvl(context->envp);
}
