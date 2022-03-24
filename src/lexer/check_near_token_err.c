/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_near_token_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:02:40 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 16:52:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_redirection_token(t_token_type type)
{
	return (
		(type == REDIR_IN)
		|| (type == REDIR_HEREDOC)
		|| (type == REDIR_OUT)
		|| (type == REDIR_APPEND)
	);
}

static t_lexer_mask	get_lexer_mask(t_token_type type)
{
	t_lexer_mask	mask;

	mask = 0;
	if (is_redirection_token(type))
		mask = REDIR_MASK;
	else if (type == PIPE)
		mask = PIPE_MASK ^ MASK_DFL;
	else if ((type == AND) || (type == OR))
		mask = LOGICAL_MASK ^ MASK_DFL;
	else if (type == PARENTHESIS_L)
		mask = PARENTHESIS_L_MASK ^ MASK_DFL;
	return (mask);
}

t_lexer_result	check_near_token_err(t_token *token)
{
	t_lexer_result	result;
	t_token_type	last_token_type;

	result = check_syntax_first_token(token);
	while (token && (result != LEXER_ERR))
	{
		if (token->type == WORD)
			result = check_word_syntax(token);
		else if (token->type == PARENTHESIS_R)
			result = check_parenthesis_r_syntax(token);
		else
		{
			result = check_syntax_by_mask(\
							token, get_lexer_mask(token->type), token->data);
		}
		if (!token->next)
			last_token_type = token->type;
		token = token->next;
	}
	if (result == LEXER_SUCCESS)
		result = check_syntax_last_token(last_token_type);
	return (result);
}
