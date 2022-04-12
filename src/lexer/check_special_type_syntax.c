/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_type_syntax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:35 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:14:48 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <unistd.h>

static void	check_word_parenthesis_comb(t_token *token, t_lexer_err *err_info)
{
	t_lexer_mask	is_word;

	is_word = 0 | WORD;
	if (
		check_prev_token_match(token, is_word)
		&& check_next_token_match(token, is_word)
	)
		set_lexer_err_info(err_info, token->next->data, NEAR_TOKEN);
}

void	check_parenthesis_l_syntax(t_token *token, t_lexer_err *err_info)
{
	t_lexer_mask	mask;

	check_word_parenthesis_comb(token, err_info);
	mask = PARENTHESIS_L_MASK ^ MASK_DFL;
	check_syntax_by_mask(token, mask, err_info);
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
		set_lexer_err_info(err_info, ")", NEAR_TOKEN);
}

void	check_parenthesis_r_syntax(t_token *token, t_lexer_err *err_info)
{
	t_lexer_mask	mask;

	mask = PARENTHESIS_R_MASK ^ MASK_DFL;
	check_syntax_by_mask(token, mask, err_info);
	search_parenthesis_l(token, err_info);
}
