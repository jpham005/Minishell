/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:07:06 by jaham             #+#    #+#             */
/*   Updated: 2022/04/05 22:21:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
int	set_in_out(int in, int out)
{
	// printf("before dup %d %d %d %d\n", in, out, fcntl(in, F_GETFD), fcntl(out, F_GETFD));
	if (!ft_dup2(in, STDIN_FILENO))
		return (0);
	ft_close(in);
	if (!ft_dup2(out, STDOUT_FILENO))
		return (0);
	ft_close(out);
	return (1);
}

int	restore_in_out(t_context *context)
{
	if (!ft_dup2(context->std_fd[0], STDIN_FILENO))
		return (0);
	if (!ft_dup2(context->std_fd[1], STDOUT_FILENO))
		return (0);
	return (1);
}
