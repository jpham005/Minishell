/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:07:06 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 12:30:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

int	set_in_out(int in, int out)
{
	if (!ft_dup2(in, STDIN_FILENO))
		return (REDIR_ERR);
	ft_close(in);
	if (!ft_dup2(out, STDOUT_FILENO))
		return (REDIR_ERR);
	ft_close(out);
	return (REDIR_SUCCESS);
}

int	restore_in_out(t_context *context)
{
	if (!ft_dup2(context->std_fd[0], STDIN_FILENO))
		return (0);
	if (!ft_dup2(context->std_fd[1], STDOUT_FILENO))
		return (0);
	return (1);
}
