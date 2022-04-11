/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_parenthesis_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:48:51 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:35:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static int	is_removable(t_token *head)
{
	ssize_t	parenthesis_cnt;

	parenthesis_cnt = 1;
	while (head && parenthesis_cnt)
	{
		if (head->type == PARENTHESIS_L)
			parenthesis_cnt++;
		else if (head->type == PARENTHESIS_R)
			parenthesis_cnt--;
		head = head->next;
	}
	return (head == NULL);
}

static void	perform_remove(t_token **head, t_token **tail)
{
	del_token(head);
	del_token(tail);
}

void	remove_parenthesis_token(t_token **tail)
{
	t_token	*head;

	head = get_head_token(*tail);
	while (head && (head->type == PARENTHESIS_L) && is_removable(head->next))
		perform_remove(&head, tail);
}
