/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:03:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 22:08:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "redirection.h"
#include <errno.h>
#include <string.h>

static void	perform_heredoc_expansion(
	char **input, t_buffer *buffer, t_context *context
)
{
	t_token	*temp;

	buffer->len = 0;
	temp = init_token(*input, WORD);
	ft_free((void **) input);
	expand_shell_param(temp, buffer, context, 1);
	del_token(&temp);
	if (buffer->len)
		*input = get_t_buffer_string(buffer);
	else
		*input = ft_strdup("");
}

static int	perform_heredoc(t_parse_tree *parse_tree, t_context *context, \
										t_heredoc *heredoc, t_buffer *buffer)
{
	char	*input;
	int		here_pipe[2];

	if (pipe(here_pipe) == -1)
		return (return_heredoc_err(parse_tree, heredoc));
	while (1)
	{
		input = ft_readline(context, "> ");
		if (is_heredoc_end(input, heredoc->limit))
			return (end_heredoc(&input, here_pipe));
		if (heredoc->quoted == NOT_QUOTED)
			perform_heredoc_expansion(&input, buffer, context);
		if (!write_heredoc_string(input, here_pipe[1]))
		{
			ft_free((void **) &input);
			return (return_heredoc_err(parse_tree, heredoc));
		}
		ft_free((void **) &input);
	}
}

t_redir_result	handle_redir_heredoc(t_parse_tree *parse_tree, \
														t_context *context)
{
	t_buffer	buffer;
	t_heredoc	heredoc;

	init_t_buffer(&buffer);
	set_heredoc_info(parse_tree->right->original_str, &heredoc, &buffer);
	parse_tree->redir->in \
		= perform_heredoc(parse_tree, context, &heredoc, &buffer);
	ft_free((void **) &(buffer.str));
	ft_free((void **) &(heredoc.limit));
	return (REDIR_SUCCESS);
}
