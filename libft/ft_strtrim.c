/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:53:03 by jaham             #+#    #+#             */
/*   Updated: 2022/03/07 02:03:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cp;

	cp = (char *) s;
	while (n--)
	{
		if (*cp == (char) c)
			return ((void *) cp);
		cp++;
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	char const	*start;
	char const	*end;
	size_t		s1_len;
	size_t		set_len;

	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	start = s1;
	end = s1 + s1_len - 1;
	while (start < end && ft_memchr(set, *start, set_len))
		start++;
	while (end >= start && ft_memchr(set, *end, set_len))
		end--;
	ret = ft_substr(s1, start - s1, end - start + 1);
	return (ret);
}
