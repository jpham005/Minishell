/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_shell_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:00:49 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 22:20:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static char	*get_new_data(t_token *token, t_context *context)
{
	char	*ret;

	try_get_expansion_str(token->data, token, context);
}

static void	try_shell_param_expansion(t_token *token, t_context *context)
{
	char	*new_data;

	while (token)
	{
		get_new_data(token, context);
		token = token->next;
	}
}

void	expand_shell_param(t_parse_tree *parse_tree, t_context *context)
{
	t_token	*expanded_token;

	expanded_token = copy_token_list(parse_tree->token);
	try_shell_param_expansion(expanded_token, context);
}
