/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:47:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 11:36:01 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>

int	ft_dup2(int fd1, int fd2)
{
	if (fd1 == fd2)
		return (1);
	if (dup2(fd1, fd2) == -1)
	{
		ft_perror("dup2", errno);
		return (0);
	}
	return (1);
}
