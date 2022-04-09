/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:25:32 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 22:49:51 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "redirection.h"

t_pipes	*init_pipes(char **cmd, t_redir *redir)
{
	t_pipes	*ret;

	ret = ft_malloc(sizeof(t_pipes), 1);
	ret->cmd = cmd;
	ret->redir = redir;
	ret->next = NULL;
	return (ret);
}

void	add_pipes(t_pipes **head, t_pipes *new)
{
	new->next = *head;
	*head = new;
}

static void	del_pipes(t_pipes **pipes)
{
	free_c_dptr(&((*pipes)->cmd));
	destroy_redir(&((*pipes)->redir));
	ft_free((void **) pipes);
}

void	clear_pipes(t_pipes **head)
{
	t_pipes	*cp;
	t_pipes	*temp;

	cp = *head;
	while (cp)
	{
		temp = cp->next;
		del_pipes(&cp);
		cp = temp;
	}
	*head = NULL;
}
