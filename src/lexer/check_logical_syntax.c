/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logical_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:40:07 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 21:43:31 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	check_logical_syntax(t_token *token)
{
	const t_token_type	logical_syntax_condition = {
		WORD,
		PARENTHESIS_R
	};

	if (!check_prev_token_match(token, \
								(t_token_type *) logical_syntax_condition, 2))
	{
		print_syntax_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}
