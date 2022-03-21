/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:40:21 by jaham             #+#    #+#             */
/*   Updated: 2022/03/07 02:00:46 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(const char *str, const char *sep)
{
	size_t	i;
	size_t	temp;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (ft_strchr(sep, str[i]))
			i++;
		temp = i;
		while (str[i] && !ft_strchr(sep, str[i]))
			i++;
		if (i != temp)
			cnt++;
	}
	return (cnt);
}

static char	*get_string(const char *str, size_t i, size_t temp)
{
	char	*ret;
	size_t	len;

	len = i - temp;
	ret = ft_malloc(sizeof(char), len + 1);
	ft_memcpy(ret, str + temp, len);
	ret[len] = '\0';
	return (ret);
}

static char	**split_string(char **ret, const char *str, const char *sep)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_strchr(sep, str[i]))
			i++;
		temp = i;
		while (str[i] && !ft_strchr(sep, str[i]))
			i++;
		if (i != temp)
			ret[j++] = get_string(str, i, temp);
	}
	ret[j] = NULL;
	return (ret);
}

char	**ft_split(const char *str, const char *sep)
{
	char	**ret;
	size_t	ret_size;

	ret_size = get_size(str, sep);
	ret = ft_malloc(sizeof(char *), ret_size + 1);
	split_string(ret, str, sep);
	return (ret);
}
