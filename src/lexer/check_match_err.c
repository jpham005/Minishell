/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:26:17 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 11:31:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	check_quote_match_err(t_token *token, t_lexer_err *err_info)
{
	char			*data;
	t_quote_mask	mask;

	data = token->data;
	mask = 0;
	while (*data)
	{
		check_quote(*data, &mask);
		data++;
	}
	if ((mask & DQUOTE))
		set_lexer_err_info(err_info, "\"", NO_MATCH);
	else if ((mask & SQUOTE))
		set_lexer_err_info(err_info, "\'", NO_MATCH);
}

static void	check_parenthesis_match_err(t_token *token, t_lexer_err *err_info)
{
	ssize_t	parenthesis_cnt;

	parenthesis_cnt = 0;
	while (token)
	{
		if (token->type == PARENTHESIS_L)
			parenthesis_cnt++;
		if (token->type == PARENTHESIS_R)
			parenthesis_cnt--;
		token = token->next;
	}
	if (parenthesis_cnt > 0)
		set_lexer_err_info(err_info, ")", NO_MATCH);
}

void	check_match_err(t_token *token, t_lexer_err *err_info)
{
	check_quote_match_err(get_tail_token(token), err_info);
	check_parenthesis_match_err(token, err_info);
}
