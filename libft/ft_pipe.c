/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:31:49 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 19:46:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		ft_perror("pipe", errno);
		return (0);
	}
	return (1);
}
