/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:33:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 11:00:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "lexer.h"
#include "libft.h"
#include "terminal.h"
#include "tokenizer.h"
#include "utils.h"

int	get_line(t_context *context, char **line)
{
	*line = ft_readline(context, NULL);
	if (!*line)
		exit_with_condition(END_TERM, context);
	if (!check_valid_str(*line))
	{
		ft_free((void **) line);
		return (0);
	}
	return (1);
}

static void	handle_lexer_err(t_context *context, t_token **token)
{
	context->exit_status = SYNTAX_ERR_EXIT_STATUS;
	heredoc(*token, context);
	clear_fd(*token);
	clear_token(token);
}

t_token	*analize_line(char *line, t_context *context)
{
	t_token	*tokenized;

	tokenized = tokenizer(line);
	if (!tokenized)
		return (NULL);
	if (lexer(tokenized) == LEXER_ERR)
	{
		handle_lexer_err(context, &tokenized);
		return (NULL);
	}
	return (tokenized);
}

void	handle_heredoc_err(t_token **token)
{
	clear_fd(*token);
	clear_token(token);
}
