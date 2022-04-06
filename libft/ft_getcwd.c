/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:18:02 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 09:45:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_getcwd(char *buf, size_t size)
{
	char	*ret;

	ret = getcwd(buf, size);
	if (!ret)
	{
		perror("getcwd");
		ft_exit(1);
	}
	return (ret);
}
