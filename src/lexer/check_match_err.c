/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:26:17 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 17:46:54 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	check_quote_match_err(t_token *token, int op)
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
	if ((mask & DQUOTE) && op)
		print_no_match_err("\"");
	else if ((mask & SQUOTE) && op)
		print_no_match_err("\'");
	if (mask)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}

static t_lexer_result	check_parenthesis_match_err(t_token *token)
{
	ssize_t	cnt;

	cnt = 0;
	while (token)
	{
		if (token->type == PARENTHESIS_L)
			cnt++;
		if (token->type == PARENTHESIS_R)
			cnt--;
		token = token->next;
	}
	if (cnt != 0)
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
	if (check_quote_match_err(token, 1) == LEXER_ERR)
		return (LEXER_ERR);
	if (check_parenthesis_match_err(cp) == LEXER_ERR)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}
