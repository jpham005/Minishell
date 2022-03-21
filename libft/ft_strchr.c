/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:00:08 by jaham             #+#    #+#             */
/*   Updated: 2022/02/05 21:34:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ret;

	ret = (char *) str;
	while (*ret && (*ret != (unsigned char) c))
		ret++;
	if (!*ret)
		return (NULL);
	return (ret);
}
