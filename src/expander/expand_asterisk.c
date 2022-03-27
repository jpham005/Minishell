/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 19:00:12 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	perform_asterisk_expansion(
	t_token *token, t_buffer *buffer, size_t *i
)
{

}

void	expand_asterisk(t_token *token, t_buffer *buffer)
{
	t_quote_mask	mask;
	size_t			i;

	mask = 0;
	i = 0;
	while (token->data[i])
	{
		check_quote(token->data[i], &mask);
		if (!check_quote_mask(&mask) && (token->data[i] == '*'))
			perform_asterisk_expansion(token, buffer, &i);
		else
			append_t_buffer(buffer, token->data[i++]);
	}
}
