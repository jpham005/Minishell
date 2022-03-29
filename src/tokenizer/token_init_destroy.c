/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:52:10 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 09:44:21 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"
#include <stdlib.h>

t_token	*init_token(const char *data, t_token_type type)
{
	t_token	*ret;

	ret = ft_malloc(sizeof(t_token), 1);
	ret->data = ft_strdup(data);
	ret->type = type;
	ret->expanded_list = NULL;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void	add_token(t_token **head, t_token *new)
{
	if (!*head)
	{
		*head = new;
		return ;
	}
	while ((*head)->next)
		head = &((*head)->next);
	(*head)->next = new;
	new->prev = *head;
}

void	del_token(t_token **target)
{
	t_token			*next_token;

	next_token = (*target)->next;
	if (!next_token)
	{
		del_tail_token(target);
		return ;
	}
	next_token->prev = (*target)->prev;
	clear_expanded_list(*target);
	ft_free((void **) &((*target)->data));
	ft_free((void **) target);
	*target = next_token;
}

void	clear_token(t_token **head)
{
	t_token	*temp;
	t_token	*cp;

	cp = *head;
	while (cp)
	{
		temp = cp->next;
		del_token(&cp);
		cp = temp;
	}
	*head = NULL;
}