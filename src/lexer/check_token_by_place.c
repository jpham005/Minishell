/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_by_place.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:48:13 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:51:41 by jaham            ###   ########.fr       */
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

void	check_syntax_first_token(t_token *token, t_lexer_err *err_info)
{
	if (token && (token->type & FIRST_TOKEN_MASK))
		set_lexer_err_info(err_info, token->data, NEAR_TOKEN);
}

void	check_syntax_linked_token(t_token *token, t_lexer_err *err_info)
{
	while (token && (err_info->type == NO_ERR))
	{
		if (token->type == WORD)
			check_word_syntax(token, err_info);
		else if (token->type == PARENTHESIS_R)
			check_parenthesis_r_syntax(token, err_info);
		else
			check_syntax_by_mask(
				token, get_lexer_mask(token->type), err_info
			);
		token = token->next;
	}
}

void	check_syntax_last_token(t_token *token, t_lexer_err *err_info)
{
	if (!(token->type & LAST_TOKEN_MASK))
		set_lexer_err_info(err_info, "newline", NEAR_TOKEN);
}
