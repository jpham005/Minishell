/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:37:43 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 14:20:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

char	*init_string(t_string *string)
{
	string->str = ft_malloc(sizeof(char), 1);
	string->size = 1;
	string->n = 0;
	return (string->str);
}

char	*append_string(t_string *string, char c)
{
	char	*temp;

	if (string->n >= string->size)
	{
		temp = ft_malloc(sizeof(char), string->size << 1);
		ft_memcpy(temp, string->str, string->n);
		free(string->str);
		string->str = temp;
		string->size <<= 1;
	}
	string->str[string->n++] = c;
	return (string->str);
}

char	*copy_string(t_string *string)
{
	char	*ret;

	if (!string->n)
		return (ft_strdup(""));
	ret = ft_malloc(sizeof(char), string->n + 1);
	ft_memcpy(ret, string->str, string->n);
	ret[string->n] = '\0';
	return (ret);
}

void	lstdel(t_buffer **cur, int fd)
{
	t_buffer	*target;

	while (*cur && (*cur)->fd != fd)
		cur = &((*cur)->next);
	if (*cur)
	{
		target = *cur;
		*cur = (*cur)->next;
		ft_free((void **) &target);
	}
}
