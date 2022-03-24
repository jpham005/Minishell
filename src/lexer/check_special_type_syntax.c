/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_type_syntax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:35 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 17:10:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	check_word_parenthesis_comb(t_token *token)
{
	if (
		check_prev_token_match(token, SPECIAL_ERR_MASK_1)
		&& (check_prev_token_match(token->prev, SPECIAL_ERR_MASK_2))
	)
	{
		print_near_token_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}

t_lexer_result	check_word_syntax(t_token *token)
{
	if (
		(check_word_parenthesis_comb(token) == LEXER_ERR)
		|| (check_syntax_by_mask(token, WORD_MASK, token->data) == LEXER_ERR)
	)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}

static t_lexer_result	search_parenthesis_l(t_token *token)
{
	ssize_t	cnt;

	cnt = -1;
	while (token)
	{
		if (token->type == PARENTHESIS_L)
			cnt++;
		else if (token->type == PARENTHESIS_R)
			cnt--;
		token = token->prev;
	}
	if (cnt != 0)
	{
		print_near_token_err(")");
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}

t_lexer_result	check_parenthesis_r_syntax(t_token *token)
{
	const t_lexer_mask	mask = PARENTHESIS_R_MASK ^ MASK_DFL;

	if (
		(check_syntax_by_mask(token, mask, token->data) == LEXER_ERR)
		|| (search_parenthesis_l(token) == LEXER_ERR)
	)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}
