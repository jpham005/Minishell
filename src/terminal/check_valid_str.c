/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:03:05 by jaham             #+#    #+#             */
/*   Updated: 2022/03/07 03:17:24 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "libft.h"
#include <stdio.h>
#include <readline/history.h>

static int	is_valid_str(char *str, t_context *context);

static int	is_valid_expanded_str(char *str, size_t i, t_context *context)
{
	char		*key;
	char		*expanded;
	size_t		key_start;
	t_envp_list	*expand_list;

	key_start = ++i;
	while (str[i])
		i++;
	key = ft_substr(str, key_start, i - key_start);
	expand_list = find_list_by_key(context->envp, key);
	safe_free((void **) &key);
	if (!expand_list)
		return (0);
	expanded = expand_list->value;
	return (is_valid_str(expanded, context));
}

static int	is_valid_str(char *str, t_context *context)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (is_valid_expanded_str(str, i, context));
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_str(const char *str, t_context *context)
{
	char	**splited;
	int		ret;
	size_t	i;

	if (!*str)
		return (0);
	splited = ft_split(str, " \t\n");
	ret = 0;
	i = 0;
	while (splited[i])
	{
		if (is_valid_str(splited[i], context))
		{
			ret = 1;
			break ;
		}
		i++;
	}
	free_c_dptr(&splited);
	add_history(str);
	return (ret);
}
