/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:14:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 19:50:51 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t	ft_waitpid(pid_t pid, int *status, int op)
{
	pid_t	ret;

	ret = waitpid(pid, status, op);
	if (ret == -1)
	{
		ft_perror("waitpid", errno);
		return (0);
	}
	return (ret);
}
