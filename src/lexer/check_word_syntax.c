/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:24:55 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 13:11:25 by jaham            ###   ########.fr       */
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
