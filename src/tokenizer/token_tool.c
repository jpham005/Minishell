/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:28:56 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 20:01:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

t_token	*copy_single_token(t_token *token)
{
	t_token	*ret;

	ret = ft_malloc(sizeof(t_token), 1);
	ret->data = token->data;
	ret->expanded_list = token->expanded_list;
	ret->type = token->type;
	ret->next = NULL;
	ret->prev = NULL;
}

t_token	*copy_token_list(t_token *head)
{
	t_token	*ret;

	while (head)
	{
		add_token(&ret, copy_single_token(head));
		head = head->next;
	}
	return (ret);
}
