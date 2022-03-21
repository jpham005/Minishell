/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:45:12 by jaham             #+#    #+#             */
/*   Updated: 2022/02/17 15:24:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (1);
	}
	return (pid);
}
