/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:54:32 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 14:32:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_result	lexer(t_token *token)
{
	t_lexer_result	result;

	result = check_near_token_err(token);
	if (result == LEXER_SUCCESS)
		result = check_match_err(token);
	return (result);
}
