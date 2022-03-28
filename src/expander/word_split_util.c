/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_split_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:22:25 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 15:51:22 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	is_in_expanded_list(t_expanded_list *expanded_list, size_t index)
{
	while (expanded_list)
	{
		if (is_in_range_index(expanded_list->start, expanded_list->end, index))
			return (1);
		expanded_list = expanded_list->next;
	}
	return (0);
}

void	check_quote_expanded(t_token *token, t_quote_mask *mask, size_t index)
{
	char	checking;

	checking = token->data[index];
	if ((checking == '\'') && (!(*mask &DQUOTE)) \
						&& !is_in_expanded_list(token->expanded_list, index))
		*mask ^= SQUOTE;
	if ((checking == '\"') && (!(*mask &SQUOTE)) \
						&& !is_in_expanded_list(token->expanded_list, index))
		*mask ^= DQUOTE;
}

void	substitute_token(t_parse_tree *parse_tree, t_token **token, \
															t_token *new_token)
{
	t_token	*next;
	t_token	*prev;

	next = (*token)->next;
	prev = (*token)->prev;
	del_token(token);
	if (next)
	{
		next->prev = get_tail_token(new_token);
		*token = next;
	}
	if (prev)
	{
		prev->next = get_head_token(new_token);
		*token = prev;
	}
	if (new_token)
	{
		get_tail_token(new_token)->next = next;
		new_token->prev = prev;
		*token = new_token;
	}
	parse_tree->token = get_head_token(*token);
}
