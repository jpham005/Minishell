/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:36:17 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 14:36:27 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (--n)
	{
		if (*(cp1++) != *(cp2++))
			return (*(--cp1) - *(--cp2));
	}
	return (*cp1 - *cp2);
}
