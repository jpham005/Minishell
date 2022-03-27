/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:05:47 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 22:53:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	get_expanded_list(
	t_token **new_token, t_token *token, size_t start, size_t end
)
{
	
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
		check_quote(token->data[end], &mask);
		end++;
	}
	if (end == (*start))
		return ;
	data = ft_substr(token->data, *start, end - (*start));
	add_token(new_token, init_token(data, WORD));
	ft_free((void **) &data);
	get_expanded_list(new_token, token, *start, end);
	*start = end;
}

void	split_token(t_parse_tree *parse_tree)
{
	t_token	*new_token;
	size_t	start;

	if (!(parse_tree->token->type & WORD))
		return ;
	new_token = NULL;
	start = 0;
	while (parse_tree->token->data[start])
	{
		perform_split(&new_token, parse_tree->token, &start);
		skip_space(parse_tree->token->data, &start);
	}
}
