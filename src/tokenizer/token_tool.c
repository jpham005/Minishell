/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:28:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 11:25:14 by jaham            ###   ########.fr       */
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

size_t	get_token_list_len(t_token *head)
{
	size_t	ret;

	ret = 0;
	while (head)
	{
		ret++;
		head = head->next;
	}
	return (ret);
}

char	**convert_token_to_dptr(t_token *head)
{
	char	**ret;
	size_t	i;

	ret = ft_malloc(sizeof(char *), get_token_list_len(head) + 1);
	i = 0;
	while (head)
	{
		ret[i] = ft_strdup(head->data);
		head = head->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
