/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_parenthesis_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:48:51 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 21:17:57 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	perform_remove(t_token **head, t_token **tail)
{
	del_token(head);
	del_token(tail);
}

void	remove_parenthesis_token(t_token **tail)
{
	t_token	*head;

	head = get_head_token(*tail);
	if (
		head
		&& (head->type == PARENTHESIS_L)
		&& ((*tail)->type == PARENTHESIS_R)
	)
		perform_remove(&head, tail);
}
