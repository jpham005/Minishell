/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:03:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 15:21:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "redirection.h"
#include <stdlib.h>

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

static void	heredoc_child(
	t_heredoc *heredoc, t_context *context, t_buffer *buffer, int here_pipe[2]
)
{
	char	*input;

	while (1)
	{
		input = ft_readline(context, "> ");
		if (is_heredoc_end(input, heredoc->limit))
			exit(end_heredoc(&input, here_pipe));
		if (heredoc->quoted == NOT_QUOTED)
			perform_heredoc_expansion(&input, buffer, context);
		if (!write_heredoc_string(input, here_pipe[1]))
		{
			ft_free((void **) &input);
			exit(1);
		}
		ft_free((void **) &input);
	}
}

static t_redir_result	perform_heredoc(t_parse_tree *parse_tree, \
					t_context *context, t_heredoc *heredoc, t_buffer *buffer)
{
	char	*input;
	int		here_pipe[2];
	int		heredoc_stat;
	pid_t	pid;

	ft_pipe(here_pipe);
	pid = ft_fork();
	if (!pid)
		heredoc_child(heredoc, context, buffer, here_pipe);
	ft_close(here_pipe[1]);
	ft_waitpid(pid, &heredoc_stat, 0);
	heredoc_stat = ft_wexitstatus(heredoc_stat);
	if (heredoc_stat == 1)
		set_redir_err(parse_tree, heredoc->limit, HEREDOC_WRITE_ERR_MESSAGE);
	else if (heredoc_stat == 2)
		return (REDIR_ERR);
	else
		parse_tree->redir->in = heredoc_stat;
	return (REDIR_SUCCESS);
}

t_redir_result	handle_redir_heredoc(t_parse_tree *parse_tree, \
														t_context *context)
{
	t_redir_result	ret;
	t_buffer		buffer;
	t_heredoc		heredoc;

	ret = REDIR_SUCCESS;
	init_t_buffer(&buffer);
	set_heredoc_info(parse_tree->right->original_str, &heredoc, &buffer);
	if (perform_heredoc(parse_tree, context, &heredoc, &buffer) == REDIR_ERR)
	{
		context->exit_status = 1;
		ret = REDIR_ERR;
	}
	ft_free((void **) &(buffer.str));
	ft_free((void **) &(heredoc.limit));
	return (ret);
}
