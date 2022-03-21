/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonpar <hyeonpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:30:06 by jaham             #+#    #+#             */
/*   Updated: 2022/02/24 22:25:55 by hyeonpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_malloc(size_t size, size_t n)
{
	void	*ret;

	ret = malloc(size * n);
	if (!ret)
	{
		perror("malloc");
		exit(1);
	}
	return (ret);
}
