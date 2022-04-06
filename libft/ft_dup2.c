/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:47:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 19:40:39 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
int	ft_dup2(int fd1, int fd2)
{
	if (((fd1 == STDIN_FILENO) && (fd2 == STDIN_FILENO)) \
		|| ((fd1 == STDOUT_FILENO) && (fd2 == STDOUT_FILENO)))
		return (1);
	if (dup2(fd1, fd2) == -1)
	{
		perror("dup2");
		printf("duping %d %d\n", fd1, fcntl(fd1, F_GETFD));
		return (0);
	}
	return (1);
}
