/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:05:01 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 17:32:39 by jaham            ###   ########.fr       */
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
	t_pid_list	*cp;

	cp = *head;
	while (cp)
	{
		temp = cp->next;
		ft_free((void **) &cp);
		cp = temp;
	}
	*head = NULL;
}

int	wait_pid_list(t_pid_list *head)
{
	int	stat;

	while (head && head->next)
	{
		ft_waitpid(head->pid, &stat, 0);
		head = head->next;
	}
	if (head && head->pid != -1)
		ft_waitpid(head->pid, &stat, 0);
	return (stat);
}
