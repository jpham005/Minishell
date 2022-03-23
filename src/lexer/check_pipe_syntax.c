/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:24:15 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 21:34:20 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	check_pipe_syntax(t_token *token)
{
	const t_token_type	pipe_syntax_condition[] = {
		WORD,
		PARENTHESIS_R
	};

	if (!check_prev_token_match(token, \
									(t_token_type *) pipe_syntax_condition, 2))
	{
		print_syntax_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}
