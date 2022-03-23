/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:29:28 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 22:22:46 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_prev_token_match(t_token *token, t_lexer_mask mask)
{
	return (token->prev && (token->prev->type & mask));
}

t_lexer_result	check_word_parenthesis_comb(t_token *token)
{
	if (
		check_prev_token_match(token, WORD_PARENTHESIS_COMB_MASK)
		&& (check_prev_token_match(token->prev, WORD_PARENTHESIS_COMB_MASK))
	)
	{
		print_syntax_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}

t_lexer_result	check_syntax_by_mask(
	t_token *token, t_lexer_mask mask, char *data
)
{
	if (check_prev_token_match(token, mask))
	{
		print_syntax_err(data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}
