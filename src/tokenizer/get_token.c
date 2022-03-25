/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:28:56 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 10:24:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_token	*get_head_token(t_token *curr)
{
	while (curr && curr->prev)
		curr = curr->prev;
	return (curr);
}

t_token	*get_tail_token(t_token *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}
