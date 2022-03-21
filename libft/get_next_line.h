/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:17:14 by jaham             #+#    #+#             */
/*   Updated: 2022/02/20 14:18:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_buffer
{
	char			buf[BUFFER_SIZE];
	char			*cur;
	char			*end;
	int				fd;
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_string
{
	char	*str;
	int		size;
	int		n;
}	t_string;

char	*init_string(t_string *string);
char	*append_string(t_string *string, char c);
char	*copy_string(t_string *string);
void	lstdel(t_buffer **cur, int fd);

#endif