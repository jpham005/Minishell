/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_near_token_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:02:40 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:49:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	check_near_token_err(t_token *token, t_lexer_err *err_info)
{
	check_syntax_first_token(token, err_info);
	check_syntax_linked_token(token, err_info);
	check_syntax_last_token(get_last_token(token), err_info);
}
