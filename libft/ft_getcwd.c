/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:18:02 by jaham             #+#    #+#             */
/*   Updated: 2022/02/17 15:24:29 by jaham            ###   ########.fr       */
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
		exit(1);
	}
	return (ret);
}
