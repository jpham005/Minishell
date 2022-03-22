/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:47:50 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 19:24:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	check_quote(char c, t_quote_mask *mask)
{
	if ((c == '\'') && ((*mask & DQUOTE) == 0))
		*mask ^= SQUOTE;
	if ((c == '\"') && ((*mask & SQUOTE) == 0))
		*mask ^= DQUOTE;
}

int	check_quote_mask(t_quote_mask mask)
{
	return ((mask & SQUOTE) || (mask & DQUOTE));
}
