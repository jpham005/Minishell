/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_shell_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:19:34 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 01:50:31 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	is_shell_param_expansion(char *data)
{
	t_quote_mask	mask;

	mask = 0;
	while (*data)
	{
		check_quote(*data, &mask);
		if ((*data == '$') && !(mask & SQUOTE))
			return (1);
		data++;
	}
	return (0);
}

void	expand_shell_param(t_token *token)
{
	t_token	*next_token;

	while (token)
	{
		next_token = token->next;
		if (is_shell_param_expansion(token->data))
			perform_shell_param_expansion(token);
		token = next_token;
	}
}
