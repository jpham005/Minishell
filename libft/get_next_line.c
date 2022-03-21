/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:36:26 by jaham             #+#    #+#             */
/*   Updated: 2022/02/20 14:18:23 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	delall(t_buffer **head, t_string *string, int fd)
{
	lstdel(head, fd);
	safe_free((void **) &(string->str));
	return (0);
}

t_buffer	*find_lst(t_buffer **target, int fd)
{
	t_buffer	*new;

	while (*target && (*target)->fd != fd)
		target = &((*target)->next);
	if (*target)
		return (*target);
	new = ft_malloc(sizeof(t_buffer), 1);
	new->fd = fd;
	new->cur = new->buf;
	new->end = new->buf;
	new->next = NULL;
	*target = new;
	return (new);
}

char	read_char(int fd, int *eof, t_buffer *curr)
{
	if (curr->cur == curr->end)
	{
		if (curr->end < curr->buf + BUFFER_SIZE && curr->end > curr->buf)
		{
			*eof = 1;
			return (0);
		}
		curr->end = curr->buf + read(fd, curr->buf, BUFFER_SIZE);
		curr->cur = curr->buf;
	}
	if (curr->cur > curr->end)
	{
		*eof = -1;
		return (0);
	}
	if (curr->cur == curr->end)
	{
		*eof = 1;
		return (0);
	}
	*eof = 0;
	return (*(curr->cur++));
}

int	read_line(int fd, t_string *string)
{
	static t_buffer	*head;
	int				eof;
	char			c;

	while (1)
	{
		c = read_char(fd, &eof, find_lst(&head, fd));
		if (eof < 0)
			return (delall(&head, string, fd));
		if (eof > 0)
		{
			lstdel(&head, fd);
			break ;
		}
		if (!append_string(string, c))
			return (delall(&head, string, fd));
		if (c == '\n')
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	t_string	string;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!init_string(&string))
		return (NULL);
	if (!read_line(fd, &string))
		return (NULL);
	ret = copy_string(&string);
	safe_free((void **) &(string.str));
	return (ret);
}
