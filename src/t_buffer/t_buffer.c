/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:10:31 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 22:16:21 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_buffer.h"

void	init_t_buffer(t_buffer *buffer)
{
	t_buffer	*ret;

	ret->str = ft_malloc(sizeof(char), BUFFER_SIZE);
	ret->len = 0;
	ret->size = 1024;
}

void	append_t_buffer(t_buffer *buffer, char c)
{
	char	*temp;

	if (buffer->len >= buffer->size)
	{
		temp = ft_malloc(sizeof(char), buffer->size << 1);
		ft_memcpy(temp, buffer->str, buffer->len);
		free(buffer->str);
		buffer->str = temp;
		buffer->size <<= 1;
	}
	buffer->str[(buffer->len)++] = c;
}
