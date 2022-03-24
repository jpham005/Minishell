/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:29:28 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 13:11:25 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_prev_token_match(t_token *token, t_lexer_mask mask)
{
	return (token->prev && (token->prev->type & mask));
}

t_lexer_result	check_syntax_first_token(t_token *token)
{
	if (token && (token->type & FIRST_TOKEN_MASK))
	{
		print_near_token_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}

t_lexer_result	check_syntax_last_token(t_token_type type)
{
	if (type & LAST_TOKEN_MASK)
		return (LEXER_SUCCESS);
	print_near_token_err("newline");
	return (LEXER_ERR);
}

t_lexer_result	check_syntax_by_mask(
	t_token *token, t_lexer_mask mask, char *data
)
{
	if (check_prev_token_match(token, mask))
	{
		print_near_token_err(data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}
