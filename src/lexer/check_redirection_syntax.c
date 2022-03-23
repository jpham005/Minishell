/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:08:41 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 21:28:15 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	check_redirection_syntax(t_token *token)
{
	const t_token_type	redirection_syntax_condition[] = {
		REDIR_IN,
		REDIR_APPEND,
		REDIR_OUT,
		REDIR_APPEND
	};

	if (
		check_prev_token_match(token, \
							(t_token_type *) redirection_syntax_condition, 4)
	)
	{
		print_syntax_err(token->data);
		return (LEXER_ERR);
	}
	return (LEXER_SUCCESS);
}
