/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:04 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 20:46:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

t_filename	*init_filename(char *filename)
{
	t_filename	*ret;

	ret = ft_malloc(sizeof(t_filename), 1);
	ret->name = ft_strdup(filename);
	ret->next = NULL;
	return (ret);
}

void	add_filename(t_filename **head, char *filename)
{
	while (*head)
		head = &((*head)->next);
	*head = init_filename(filename);
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
