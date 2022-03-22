/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:48:09 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 14:20:33 by jaham            ###   ########.fr       */
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

void	sort_envp_dptr(char **envp)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (envp[i + 1])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[j]) + 1) > 0)
			{
				temp = envp[i];
				envp[i] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
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
		cp->next->value = ft_strdup(head->value);
		head = head->next;
		cp = cp->next;
		len++;
	}
	cp->next = NULL;
	cp_head.next->list_len = len;
	return (cp_head.next);
}
