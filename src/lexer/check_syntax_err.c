/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:02:40 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 22:42:49 by jaham            ###   ########.fr       */
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

static t_lexer_result	check_first_place_syntax(t_token *token)
{
	if (token && )
}

static t_lexer_mask	get_lexer_mask_by_type(t_token_type type)
{
	t_lexer_mask	mask;

	mask = MASK_DFL;
	if (is_redirection_token(type))
		mask = REDIR_MASK;
	else if (type == PIPE)
		mask = PIPE_MASK;
	return (mask);
}

t_lexer_result	check_syntax_err(t_token *token)
{
	t_lexer_result	result;
	t_lexer_mask	mask;

	result = check_first_place_syntax(token);
	while (token && (result != LEXER_ERR))
	{
		if (check_word_parenthesis_comb(token))
			result = LEXER_ERR;
		else
		{
			mask = get_lexer_mask_by_type(token->type);
			result = check_syntax_by_mask(token, mask, token->data);
		}
		// else if (is_redirection_token(token->type))
		// 	result = check_syntax_by_mask(token, REDIR_MASK, token->data);
		// else if (token->type == PIPE)
		// 	result = check_syntax_by_mask(token, PIPE_MASK, token->data);
		// else if ((token->type == AND) || (token->type == OR))
		// 	result = check_logical_syntax(token);
		// else if (token->type == PARENTHESIS_L)
		// 	result = check_parenthesis_l_syntax(token);
		// else if (token->type == PARENTHESIS_R)
		// 	result = check_parenthesis_r_syntax(token);
		// else if (!token->next)
		// 	result = check_newline_syntax(token);
		// else
		// 	result = LEXER_SUCCESS;// ERR
		token = token->next;
	}
	return (result);
}
