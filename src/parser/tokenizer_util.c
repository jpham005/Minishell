/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:38:35 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 22:32:10 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <ctype.h>

int	is_split_condition(char c, t_quote_mask mask)
{
	return (
		(c == 0)
		|| (ft_isspace(c) && (check_quote_mask(mask) == 0))
	);
}

void	skip_space(const char *str, size_t *start)
{
	if (str[*start] && ft_isspace(str[*start]))
		(*start)++;
}
