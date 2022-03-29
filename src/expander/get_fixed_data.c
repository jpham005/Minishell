/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fixed_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:37 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 11:53:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static int	is_valid_asterisk(
	char c, t_expanded_list *expanded_list, size_t i, t_quote_mask *mask
)
{
	return ((c == '*') && !check_quote_mask(*mask));
}

static int	is_valid_quote(
	char c, t_expanded_list *expanded_list, size_t i, t_quote_mask *mask
)
{
	if ((c != '\'') && (c != '\"') \
		|| ((c == '\'') && (*mask & DQUOTE)) \
		|| ((c == '\"') && (*mask & SQUOTE)))
		return (0);
	while (expanded_list)
	{
		if (is_in_range_index(expanded_list->start, expanded_list->end, i))
			return (0);
		expanded_list = expanded_list->next;
	}
	return (1);
}

static char	*get_fixed_string(t_token *token, t_buffer *buffer, size_t *i)
{
	t_quote_mask	mask;

	buffer->len = 0;
	mask = 0;
	while (token->data[*i] \
		&& !is_valid_asterisk(token->data[*i], token->expanded_list, *i, &mask))
	{
		check_quote_expanded(token, &mask, *i);
		if (!is_valid_quote(token->data[*i], token->expanded_list, *i, &mask))
			append_t_buffer(buffer, token->data[*i]);
		(*i)++;
	}
	return (get_t_buffer_string(buffer));
}

static char	*get_asterisk_string(t_token *token, t_buffer *buffer, size_t *i)
{
	buffer->len = 0;
	while (token->data[*i] == '*')
	{
		append_t_buffer(buffer, token->data[*i]);
		(*i)++;
	}
	return (get_t_buffer_string(buffer));
}

void	get_fixed_data(t_filename **head, t_token *token)
{
	t_buffer	buffer;
	char		*appending;
	size_t		i;

	init_t_buffer(&buffer);
	i = 0;
	while (token->data[i])
	{
		appending = get_fixed_string(token, &buffer, &i);
		if (buffer.len != 0)
			add_filename(head, appending, FIXED_STR);
		ft_free((void **) &appending);
		appending = get_asterisk_string(token, &buffer, &i);
		if (buffer.len != 0)
			add_filename(head, appending, ASTERISK);
		ft_free((void **) &appending);
	}
	ft_free((void **) &(buffer.str));
}
