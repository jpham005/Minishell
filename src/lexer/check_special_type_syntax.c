/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_type_syntax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:35 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:55:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	check_word_parenthesis_comb(t_token *token, t_lexer_err *err_info)
{
	if (
		check_prev_token_match(token, SPECIAL_ERR_MASK_1)
		&& (check_prev_token_match(token->prev, SPECIAL_ERR_MASK_2))
	)
		set_lexer_err_info(err_info, token->data, NEAR_TOKEN);
}

void	check_word_syntax(t_token *token, t_lexer_err *err_info)
{
	check_quote_match_err(token, err_info);
	check_word_parenthesis_comb(token, err_info);
	check_syntax_by_mask(token, WORD_MASK, err_info);
}

static void	search_parenthesis_l(t_token *token, t_lexer_err *err_info)
{
	ssize_t	cnt;

	cnt = 0;
	while (token)
	{
		if (token->type == PARENTHESIS_L)
			cnt++;
		else if (token->type == PARENTHESIS_R)
			cnt--;
		token = token->prev;
	}
	if (cnt < 0)
		set_lexer_err_info(err_info, token->data, NEAR_TOKEN);
}

void	check_parenthesis_r_syntax(t_token *token, t_lexer_err *err_info)
{
	const t_lexer_mask	mask = PARENTHESIS_R_MASK ^ MASK_DFL;

	check_syntax_by_mask(token, mask, err_info);
	search_parenthesis_l(token, err_info);
}
