/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:44:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 19:45:22 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>

int	ft_dup(int fd)
{
	int	ret;

	ret = dup(fd);
	if (ret < 0)
	{
		ft_perror("dup", errno);
		return (-1);
	}
	return (ret);
}
