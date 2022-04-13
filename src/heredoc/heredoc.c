/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:01 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 10:58:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

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
