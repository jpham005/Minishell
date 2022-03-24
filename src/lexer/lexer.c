/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:54:32 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 21:30:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_lexer_result	get_lexer_result(t_lexer_err *err_info)
{
	if (err_info->type != NO_ERR)
		return (LEXER_ERR);
	return (LEXER_SUCCESS);
}

t_lexer_result	lexer(t_token *token)
{
	t_lexer_result	result;
	t_lexer_err		err_info;

	init_lexer_err_info(&err_info);
	check_near_token_err(token, &err_info);
	check_match_err(token, &err_info);
	result = get_lexer_result(&err_info);
	if (result == LEXER_ERR)
		print_lexer_err(&err_info);
	clear_lexer_err_info(&err_info);
	return (result);
}
