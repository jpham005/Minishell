/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_near_token_err_util.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:29:28 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:53:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

int	check_prev_token_match(t_token *token, t_lexer_mask mask)
{
	return (token->prev && (token->prev->type & mask));
}

void	check_syntax_by_mask(
	t_token *token, t_lexer_mask mask, t_lexer_err *err_info
)
{
	if (check_prev_token_match(token, mask))
		set_lexer_err_info(err_info, token->data, NEAR_TOKEN);
}
