/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:14:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 19:46:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	ft_waitpid(pid_t pid, int *status, int op)
{
	if (waitpid(pid, status, op) == -1)
	{
		ft_perror("waidpid", errno);
		return (0);
	}
	return (1);
}
