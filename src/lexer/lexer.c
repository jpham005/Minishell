/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:54:32 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:59:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>
t_lexer_result	lexer(t_token *token)
{
	t_lexer_result	result;
	t_lexer_err		err_info;

	result = LEXER_SUCCESS;
	init_lexer_err_info(&err_info);
	check_near_token_err(token, &err_info);
	check_match_err(token, &err_info);
	if (err_info.type != NO_ERR)
	{
		print_lexer_err(&err_info);
		result = LEXER_ERR;
	}
	printf("%d\n", err_info.type);
	clear_lexer_err_info(&err_info);
	return (result);
}
