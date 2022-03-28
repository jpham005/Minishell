/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:38:35 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 13:52:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"

int	is_meta_char(char c)
{
	return (
		(c == '<')
		|| (c == '>')
		|| (c == '|')
		|| (c == '&')
		|| (c == '(')
		|| (c == ')')
	);
}

int	is_double_meta_char(const char *str, size_t start)
{
	return (
		(str[start] == str[start + 1])
		&& str[start] != '('
		&& str[start] != ')'
	);
}

int	is_split_condition(char c, t_quote_mask mask)
{
	return (
		(c == 0)
		|| ((check_quote_mask(mask) == 0) && (ft_isspace(c) || is_meta_char(c)))
	);
}

void	skip_space(const char *str, size_t *start)
{
	while (str[*start] && ft_isspace(str[*start]))
		(*start)++;
}
