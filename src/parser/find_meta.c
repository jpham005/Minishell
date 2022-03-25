/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_meta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:03:26 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 19:14:23 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <sys/types.h>
#include <stdlib.h>

static void	check_parenthesis(t_token_type type, ssize_t *parenthesis_cnt)
{
	if (type == PARENTHESIS_L)
		(*parenthesis_cnt)++;
	if (type == PARENTHESIS_R)
		(*parenthesis_cnt)--;
}

static t_search_result	find_from_head(t_token *head, t_token **searched, \
															t_meta_type type)
{
	ssize_t	parenthesis_cnt;

	parenthesis_cnt = 0;
	while (head)
	{
		check_parenthesis(head->type, &parenthesis_cnt);
		if ((head->type & type) && (parenthesis_cnt == 0))
		{
			*searched = head;
			return (FOUND);
		}
		head = head->next;
	}
	*searched = NULL;
	return (NOT_FOUND);
}

static t_search_result	find_from_tail(t_token *tail, t_token **searched, \
															t_meta_type type)
{
	ssize_t	parenthesis_cnt;

	parenthesis_cnt = 0;
	while (tail)
	{
		check_parenthesis(tail->type, &parenthesis_cnt);
		if ((tail->type & type) && (parenthesis_cnt == 0))
		{
			*searched = tail;
			return (FOUND);
		}
		tail = tail->prev;
	}
	*searched = NULL;
	return (NOT_FOUND);
}

t_search_result	find_meta(t_token *tail, t_token **searched, t_meta_type type)
{
	if (type == REDIRECTION_META)
		return (find_from_head(get_head_token(tail), searched, type));
	return (find_from_tail(tail, searched, type));
}
