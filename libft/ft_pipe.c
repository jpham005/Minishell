/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:31:49 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 14:39:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	return (1);
}
