/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:20:24 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 14:20:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "libft.h"

void	del_one_envp_list(t_envp_list **head, const char *key)
{
	t_envp_list	*temp;
	t_envp_list	*cp;

	cp = *head;
	while (*head && ft_strncmp((*head)->key, key, ft_strlen(key) + 1))
		head = &((*head)->next);
	if (*head)
	{
		temp = *head;
		*head = (*head)->next;
		ft_free((void **) &(temp->key));
		ft_free((void **) &(temp->value));
		ft_free((void **) &temp);
		cp->list_len--;
	}
}

void	update_envp_list(t_envp_list **head, const char *key, const char *value)
{
	t_envp_list	*new;
	t_envp_list	*cp;

	cp = *head;
	while (*head && ft_strncmp((*head)->key, key, ft_strlen(key) + 1))
		head = &((*head)->next);
	if (*head)
	{
		ft_free((void **) &((*head)->value));
		(*head)->value = ft_strdup(value);
		return ;
	}
	new = ft_malloc(sizeof(t_envp_list), 1);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	*head = new;
	cp->list_len++;
}

int	clear_envp_list(t_envp_list **head)
{
	t_envp_list	*cp;
	t_envp_list	*temp;

	cp = *head;
	while (cp)
	{
		ft_free((void **) &(cp->key));
		ft_free((void **) &(cp->value));
		temp = cp->next;
		ft_free((void **) &cp);
		cp = temp;
	}
	*head = NULL;
	return (0);
}

int	init_envp_list(t_envp_list **head, const char **envp)
{
	t_envp_list	**cp;
	size_t		len;

	cp = head;
	len = 0;
	while (envp[len])
	{
		*head = ft_malloc(sizeof(t_envp_list), 1);
		(*head)->next = NULL;
		get_key(*head, envp[len]);
		get_value(*head, envp[len]);
		head = &((*head)->next);
		len++;
	}
	*head = NULL;
	(*cp)->list_len = len;
	return (1);
}
