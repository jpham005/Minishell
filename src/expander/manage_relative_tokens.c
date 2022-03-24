/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_relative_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:51:23 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 01:56:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	get_relative_tokens(t_relative_tokens *relative_tokens, t_token *token)
{
	relative_tokens->prev = token->prev;
	relative_tokens->curr = token;
	relative_tokens->next = token->next;
}

void	append_new_tokens(t_relative_tokens *relative_tokens, t_token *token)
{
	del_token(relative_tokens->curr);
	relative_tokens->prev->next = token;
	relative_tokens->next->prev = get_last_token(token)->next;
}
