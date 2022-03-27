/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_with_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:53:57 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 17:19:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static int	is_envable_char(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

static char	*get_key_from_string(char *str, size_t *i)
{
	size_t	j;
	char	*key;

	(*i)++;
	j = *i;
	while (is_envable_char(str[j]))
		j++;
	key = ft_malloc(sizeof(char), j - (*i) + 2);
	ft_memcpy(key + 1, str + (*i), j - (*i));
	key[0] = '$';
	key[j + 1] = '\0';
	*i = j;
	return (key);
}

void	expand_with_envp(
	t_token *token, t_buffer *buffer, t_context *context, size_t *i
)
{
	char		*key;
	size_t		start;
	t_envp_list	*curr_list;

	start = *i;
	key = get_key_from_string(token->data, i);
	curr_list = find_list_by_key(context->envp, key + 1);
	if (curr_list)
		append_expanded(buffer, curr_list->value, start, token);
	else
		append_t_buffer_string(buffer, key);
	ft_free((void **) &key);
}
