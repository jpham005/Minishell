/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:05 by jaham             #+#    #+#             */
/*   Updated: 2022/02/10 15:50:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = ft_malloc(sizeof(char), len + 1);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
