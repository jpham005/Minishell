/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:21:18 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 03:15:10 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "libft.h"
#include <stdio.h>

static void	print_envp_export(t_envp_list *head)
{
	t_envp_list	*sorted;
	t_envp_list	*cp;

	sorted = get_sort_envp_list(head);
	cp = sorted;
	while (sorted)
	{
		if (sorted->value)
			printf("declare -x %s=\"%s\"\n", sorted->key, sorted->value);
		else
			printf("declare -x %s\n", sorted->key);
		sorted = sorted->next;
	}
	clear_envp_list(&cp);
}

static void	print_envp_env(t_envp_list *head)
{
	while (head)
	{
		if (head->value)
			printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}

void	print_envp(t_envp_list *head, int op)
{
	if (op & SORT)
		print_envp_export(head);
	else
		print_envp_env(head);
}
