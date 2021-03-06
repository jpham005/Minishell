/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:05:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:05:25 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "tokenizer.h"

static void	get_expanded_list(
	t_token **new_token, t_token *token, size_t start, size_t end
)
{
	t_expanded_list	*cp;

	cp = token->expanded_list;
	while (cp)
	{
		if (is_in_range_index(cp->start, cp->end, start) \
			|| is_in_range_index(cp->start, cp->end, end) \
			|| is_in_range_index(start, end, cp->start))
		{
			add_expanded_list(&((*new_token)->expanded_list), \
			init_expanded_list(ft_max(cp->start, start) - start, \
			ft_min(cp->end, end) - start));
		}
		cp = cp->next;
	}
}

static void	perform_split(t_token **new_token, t_token *token, size_t *start)
{
	t_quote_mask	mask;
	size_t			end;
	char			*data;

	mask = 0;
	end = *start;
	while (!is_split_condition(token->data[end], mask))
	{
		check_quote_expanded(token, &mask, end);
		end++;
	}
	if (end == (*start))
		return ;
	data = ft_substr(token->data, *start, end - (*start));
	add_token(new_token, init_token(data, WORD));
	ft_free((void **) &data);
	get_expanded_list(new_token, token, *start, end - 1);
	*start = end;
}

void	word_split(t_parse_tree *parse_tree, t_token **token)
{
	t_token	*new_token;
	size_t	start;

	if (!*token || !((*token)->type & WORD))
		return ;
	new_token = NULL;
	start = 0;
	while ((*token)->data[start])
	{
		perform_split(&new_token, *token, &start);
		skip_space((*token)->data, &start);
	}
	clear_expanded_list(*token);
	substitute_token(parse_tree, token, new_token);
}
