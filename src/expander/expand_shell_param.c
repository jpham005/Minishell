/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_shell_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:00:49 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 20:40:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	perform_shell_expansion(
	t_token *token, t_buffer *buffer, t_context *context, size_t *i
)
{
	if (!ft_strncmp(token->data + (*i), "$?", 2))
		expand_with_exit_status(token, buffer, context, i);
	else
		expand_with_envp(token, buffer, context, i);
}

void	expand_shell_param(t_token *token, t_buffer *buffer, \
										t_context *context, int is_heredoc)
{
	t_quote_mask	mask;
	size_t			i;

	buffer->len = 0;
	mask = 0;
	i = 0;
	while (token->data[i])
	{
		check_quote(token->data[i], &mask);
		if ((!(mask & SQUOTE) || is_heredoc) && (token->data[i] == '$'))
			perform_shell_expansion(token, buffer, context, &i);
		else
			append_t_buffer(buffer, token->data[i++]);
	}
}
