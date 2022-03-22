/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:48:09 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 22:33:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"
#include <ctype.h>

static t_token_type	get_token_type(const char *data)
{
	return (WORD);
}

static char	*get_token_data(const char *str, size_t *start)
{
	t_quote_mask	quote_mask;
	size_t			end;
	char			*ret;

	quote_mask = 0;
	end = *start;
	while (!is_split_condition(str[end], quote_mask))
	{

		check_quote(str[end], &quote_mask);
		end++;
	}
	ret = ft_substr(str, *start, end - (*start));
	*start = end;
	return (ret);
}

t_token	*tokenize(const char *str)
{
	t_token			*head;
	size_t			start;
	char			*data;

	head = NULL;
	start = 0;
	while (str[start])
	{
		data = get_token_data(str, &start);
		skip_space(str, &start);
		add_token(&head, init_token(data, get_token_type(data)));
		ft_free((void **) &data);
	}
	return (head);
}
