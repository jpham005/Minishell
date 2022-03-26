/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buffer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:36 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 22:13:59 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BUFFER_H
# define T_BUFFER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <ctype.h>

typedef struct s_buffer	t_buffer;

struct s_buffer
{
	char	*str;
	size_t	len;
	size_t	size;
};

void	init_t_buffer(t_buffer *buffer);
void	append_t_buffer(t_buffer *buffer, char c);

#endif