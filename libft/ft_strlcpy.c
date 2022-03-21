/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:07:04 by hyeonpar          #+#    #+#             */
/*   Updated: 2022/03/06 13:29:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] != '\0')
		len++;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && *(src + i) != '\0')
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (len);
}
