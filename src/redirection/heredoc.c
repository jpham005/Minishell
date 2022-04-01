/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:03:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/01 21:48:48 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "redirection.h"
#include <errno.h>
#include <string.h>

static int	close_return_pipe(int here_pipe[2])
{
	close(here_pipe[1]);
	return (here_pipe[0]);
}

static int	return_pipe_err(t_parse_tree *parse_tree, t_heredoc *heredoc)
{
	set_redir_err(parse_tree, heredoc->limit, strerror(errno));
	return (-1);
}

static void	perform_heredoc_expansion(
	char **input, t_buffer *buffer, t_context *context
)
{
	t_token	*temp;

	buffer->len = 0;
	temp = init_token(*input, WORD);
	expand_shell_param(temp, buffer, context);
	ft_free((void **) input);
	*input = temp->data;
	ft_free((void **) &temp);
}

static int	get_heredoc_data(t_parse_tree *parse_tree, t_context *context, \
										t_heredoc *heredoc, t_buffer *buffer)
{
	char	*input;
	int		here_pipe[2];

	if (pipe(here_pipe) == -1)
		return (return_pipe_err(parse_tree, heredoc));
	while (1)
	{
		input = ft_readline(context, "> ");
		if (is_heredoc_end(input, heredoc->limit))
		{
			ft_free((void **) &input);
			return (close_return_pipe(here_pipe));
		}
		if (heredoc->quoted == QUOTED)
			perform_heredoc_expansion(&input, buffer, context);
		if ((ft_putstr_fd(input, here_pipe[1]) == -1) \
			|| (ft_putstr_fd("\n", here_pipe[1]) == -1))
		{
			ft_free((void **) &input);
			return (return_pipe_err(parse_tree, heredoc));
		}
		ft_free((void **) &input);
	}
}

void	handle_redir_heredoc(t_parse_tree *parse_tree, t_context *context)
{
	t_buffer	buffer;
	t_heredoc	heredoc;

	init_t_buffer(&buffer);
	set_heredoc_info(parse_tree->original_str, &heredoc, &buffer);
	get_heredoc_data(parse_tree, context, &heredoc, &buffer);
}
