/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:14:48 by jaham             #+#    #+#             */
/*   Updated: 2022/02/20 19:59:52 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_waitpid(pid_t pid, int *status, int op)
{
	if (waitpid(pid, status, op) == -1)
	{
		perror("waidpid");
		exit(1);
	}
}
