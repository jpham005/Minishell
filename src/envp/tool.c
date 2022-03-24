/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:48:09 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 03:17:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "libft.h"

char	**convert_envp_to_dptr(const t_envp_list *head)
{
	char	**ret;
	char	*temp;
	size_t	i;
	size_t	len;

	len = head->list_len;
	ret = ft_malloc(sizeof(char *), head->list_len + 1);
	i = 0;
	while (i < len)
	{
		ret[i] = ft_strjoin(head->key, "=");
		temp = ft_strjoin(ret[i], head->value);
		ft_free(((void **) &ret[i]));
		ret[i] = temp;
		head = head->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static void	swap_envp_list(t_envp_list *list1, t_envp_list *list2)
{
	char	*temp_key;
	char	*temp_value;

	temp_key = list1->key;
	temp_value = list1->value;
	list1->key = list2->key;
	list1->value = list2->value;
	list2->key = temp_key;
	list2->value = temp_value;
}

t_envp_list	*get_sort_envp_list(t_envp_list *head)
{
	t_envp_list	*ret;
	t_envp_list	*temp;
	t_envp_list	*cp;

	cp = copy_envp_list(head);
	ret = cp;
	while (cp->next)
	{
		temp = cp->next;
		while (temp)
		{
			if (ft_strncmp(cp->key, temp->key, ft_strlen(temp->key) + 1) > 0)
			{
				swap_envp_list(cp, temp);
			}
			temp = temp->next;
		}
		cp = cp->next;
	}
	return (ret);
}

t_envp_list	*find_list_by_key(t_envp_list *head, const char *key)
{
	while (head && ft_strncmp(head->key, key, ft_strlen(key) + 1))
		head = head->next;
	return (head);
}

t_envp_list	*copy_envp_list(t_envp_list *head)
{
	t_envp_list	*cp;
	t_envp_list	cp_head;
	size_t		len;

	cp = &cp_head;
	len = 0;
	while (head)
	{
		cp->next = ft_malloc(sizeof(t_envp_list), 1);
		cp->next->key = ft_strdup(head->key);
		if (head->value)
			cp->next->value = ft_strdup(head->value);
		else
			cp->next->value = NULL;
		head = head->next;
		cp = cp->next;
		len++;
	}
	cp->next = NULL;
	cp_head.next->list_len = len;
	return (cp_head.next);
}
