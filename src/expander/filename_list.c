/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:04 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 14:26:20 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

t_filename	*init_filename(char *filename, t_nametype type)
{
	t_filename	*ret;

	ret = ft_malloc(sizeof(t_filename), 1);
	ret->name = ft_strdup(filename);
	ret->checked = ret->name;
	ret->type = type;
	ret->next = NULL;
	return (ret);
}

void	add_filename(t_filename **head, char *filename, t_nametype type)
{
	while (*head)
		head = &((*head)->next);
	*head = init_filename(filename, type);
}

void	del_one_filename(t_filename **head, t_filename *target)
{
	t_filename	*temp;

	while (*head && ((*head) != target))
		head = &((*head)->next);
	if (*head)
	{
		temp = (*head)->next;
		ft_free((void **) &((*head)->name));
		ft_free((void **) head);
		*head = temp;
	}
}

void	clear_filename(t_filename **head)
{
	t_filename	*temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_free((void **) &((*head)->name));
		ft_free((void **) head);
		*head = temp;
	}
}
