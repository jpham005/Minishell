/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init_destroy_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:32:46 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 16:37:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include "tokenizer.h"

void	del_expanded_list(t_expanded_list **head, size_t start)
{
	t_expanded_list	*target;

	while (*head && (*head)->start != start)
		head = &((*head)->next);
	if (*head)
	{
		target = *head;
		*head = (*head)->next;
		ft_free((void **) &target);
	}
}

void	clear_expanded_list(t_token *token)
{
	t_expanded_list	*temp;

	while (token->expanded_list)
	{
		temp = token->expanded_list->next;
		ft_free((void **) &(token->expanded_list));
		token->expanded_list = temp;
	}
}

void	del_tail_token(t_token **target)
{
	t_token	*prev_token;

	prev_token = (*target)->prev;
	if (prev_token)
		prev_token->next = NULL;
	clear_expanded_list(*target);
	ft_free((void **) &((*target)->data));
	destroy_redir(&((*target)->redir));
	ft_free((void **) target);
	*target = prev_token;
}

t_expanded_list	*init_expanded_list(size_t start, size_t end)
{
	t_expanded_list	*ret;

	ret = ft_malloc(sizeof(t_expanded_list), 1);
	ret->start = start;
	ret->end = end;
	ret->next = NULL;
	return (ret);
}

void	add_expanded_list(t_expanded_list **head, t_expanded_list *new)
{
	if (!*head)
	{
		*head = new;
		return ;
	}
	while (*head)
		head = &((*head)->next);
	*head = new;
}
