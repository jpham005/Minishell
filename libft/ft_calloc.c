/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:39:40 by hyeonpar          #+#    #+#             */
/*   Updated: 2022/03/06 13:28:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	const size_t	mem = count * size;
	void			*p;

	p = ft_malloc(sizeof(size_t), mem);
	if (!p)
		return (NULL);
	ft_bzero(p, mem);
	return (p);
}
