/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:05:01 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 21:34:31 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

static t_pid_list	*init_pid_list(pid_t pid)
{
	t_pid_list	*ret;

	ret = ft_malloc(sizeof(t_pid_list), 1);
	ret->pid = pid;
	ret->next = NULL;
	return (ret);
}

void	add_pid_list(t_pid_list **head, pid_t pid)
{
	while (*head)
		head = &((*head)->next);
	*head = init_pid_list(pid);
}

void	clear_pid_list(t_pid_list **head)
{
	t_pid_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_free((void **) head);
		head = &temp;
	}
}

int	wait_pid_list(t_pid_list *head)
{
	int	stat;

	while (head && head->next)
	{
		ft_waitpid(head->pid, NULL, 0);
		head = head->next;
	}
	if (head)
		ft_waitpid(head->pid, &stat, 0);
	return (stat);
}
