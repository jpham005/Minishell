/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:26:17 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 14:53:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_lexer_result	check_quote_match_err(t_token *token)
{
	char			*data;
	t_quote_mask	mask;

	if (token->type != WORD)
		return (LEXER_SUCCESS);
	data = token->data;
	mask = 0;
	while (*data)
	{
		check_quote(*data, &mask);
		data++;
	}
	if (mask)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}

t_lexer_result	check_match_err(t_token *token)
{
	ssize_t			parenthesis_cnt;
	t_token			*cp;
	t_lexer_result	result;

	cp = token;
	while (token->next)
		token = token->next;
	if (check_quote_match_err(token) == LEXER_ERR)
		return (LEXER_ERR);
	if (check_parenthesis_match_err(cp) == LEXER_ERR)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}

