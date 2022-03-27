/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:03:43 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 17:19:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

void	substitute_data(t_token *token, t_buffer *buffer)
{
	ft_free((void **) &(token->data));
	token->data = get_t_buffer_string(buffer);
}

void	append_expanded(
	t_buffer *buffer, char *expanded_data, size_t start, t_token *token
)
{
	size_t	end;

	append_t_buffer_string(buffer, expanded_data);
	end = buffer->len - 1;
	add_expanded_list(&(token->expanded_list), init_expanded_list(start, end));
}
