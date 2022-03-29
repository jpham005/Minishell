/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:03:43 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 11:38:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	del_token_from_tree(t_parse_tree *parse_tree, t_token *token)
{
	t_token	*prev;
	t_token	*next;
	t_token	*temp;

	while (parse_tree->token != token)
		parse_tree->token = parse_tree->token->next;
	prev = parse_tree->token->prev;
	next = parse_tree->token->next;
	ft_free((void **) &(parse_tree->token->data));
	clear_expanded_list(parse_tree->token);
	ft_free((void **) &parse_tree->token);
	temp = NULL;
	if (prev)
	{
		prev->next = next;
		temp = prev;
	}
	if (next)
	{
		next->prev = prev;
		temp = next;
	}
	parse_tree->token = get_head_token(temp);
}

void	substitute_data(
	t_parse_tree *parse_tree, t_token **token, t_buffer *buffer
)
{
	if (!buffer->len)
	{
		del_token_from_tree(parse_tree, *token);
		*token = NULL;
		return ;
	}
	ft_free((void **) &((*token)->data));
	(*token)->data = get_t_buffer_string(buffer);
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

int	is_in_range_index(size_t start, size_t end, size_t index)
{
	return ((start <= index) && (index <= end));
}
