/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:52:10 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 20:27:03 by jaham            ###   ########.fr       */
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
	ret->expand_stat = NOT_EXPANDED;
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
	t_token	*temp;

	temp = (*target)->next;
	if (temp)
		temp->prev = (*target)->prev;
	free((*target)->data);
	ft_free((void **) target);
	*target = temp;
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

t_token	*get_last_token(t_token *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
