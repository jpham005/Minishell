/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:01 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 18:45:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "tokenizer.h"

static int	is_valid_token(char *data)
{
	t_quote_mask	mask;

	mask = 0;
	while (*data)
	{
		check_quote(*data, &mask);
		++data;
	}
	return (!check_quote_mask(mask));
}

static int	is_heredoc(t_token *token)
{
	if (!token)
		return (0);
	return (token && (token->type & WORD) && token->prev \
			&& (token->prev->type & REDIR_HEREDOC) \
			&& is_valid_token(token->data));
}

int	heredoc(t_token *token, t_context *context)
{
	while (token)
	{
		if (is_heredoc(token) \
			&& handle_heredoc(token, context) == REDIR_ERR)
			return (0);
		token = token->next;
	}
	return (1);
}
