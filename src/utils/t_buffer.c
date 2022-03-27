/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:10:31 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 14:52:45 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_buffer.h"

void	init_t_buffer(t_buffer *buffer)
{
	buffer->str = ft_malloc(sizeof(char), BUFFER_SIZE);
	buffer->len = 0;
	buffer->size = 1024;
}

void	append_t_buffer(t_buffer *buffer, char c)
{
	char	*temp;

	if (buffer->len >= buffer->size)
	{
		temp = ft_malloc(sizeof(char), buffer->size << 1);
		ft_memcpy(temp, buffer->str, buffer->len);
		ft_free((void **) &buffer->str);
		buffer->str = temp;
		buffer->size <<= 1;
	}
	buffer->str[(buffer->len)++] = c;
}

void	append_t_buffer_string(t_buffer *buffer, char *str)
{
	char	*temp;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		append_t_buffer(buffer, str[i]);
		i++;
	}
}

char	*get_t_buffer_string(t_buffer *buffer)
{
	char	*ret;

	ret = ft_malloc(sizeof(char), buffer->len + 1);
	ft_memcpy(ret, buffer->str, buffer->len);
	ret[buffer->len] = '\0';
	return (ret);
}
