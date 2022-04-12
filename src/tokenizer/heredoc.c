/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:20:06 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:16:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "expander.h"
#include "terminal.h"
#include "tokenizer.h"

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
			ft_exit(end_heredoc(&input, here_pipe));
		if (heredoc->quoted == NOT_QUOTED)
			perform_heredoc_expansion(&input, buffer, context);
		write_heredoc_string(input, here_pipe[1]);
		ft_free((void **) &input);
	}
}

static t_redir_result	return_with_status(
	int heredoc_stat, int here_pipe[2], t_token *token, t_heredoc *heredoc
)
{
	if (heredoc_stat == 1)
	{
		ft_close(here_pipe[0]);
		token->prev->redir->err_target = ft_strdup(heredoc->limit);
		token->prev->redir->err = ft_strdup(HEREDOC_WRITE_ERR_MESSAGE);
	}
	else if (heredoc_stat == 2)
	{
		ft_close(here_pipe[0]);
		return (REDIR_ERR);
	}
	else
		token->prev->redir->in = here_pipe[0];
	return (REDIR_SUCCESS);
}

static t_redir_result	perform_heredoc(
	t_token *token, t_context *context, t_heredoc *heredoc, t_buffer *buffer
)
{
	int		here_pipe[2];
	int		heredoc_stat;
	pid_t	pid;

	if (!ft_pipe(here_pipe))
		return (REDIR_ERR);
	pid = ft_fork();
	if (pid == -1)
		return (REDIR_ERR);
	if (!pid)
		heredoc_child(heredoc, context, buffer, here_pipe);
	ft_close(here_pipe[1]);
	ft_waitpid(pid, &heredoc_stat, 0);
	heredoc_stat = ft_wexitstatus(heredoc_stat);
	return (return_with_status(heredoc_stat, here_pipe, token, heredoc));
}

t_redir_result	handle_heredoc(t_token *token, t_context *context)
{
	t_redir_result	ret;
	t_buffer		buffer;
	t_heredoc		heredoc;

	ret = REDIR_SUCCESS;
	init_t_buffer(&buffer);
	set_heredoc_info(token->data, &heredoc, &buffer);
	if (perform_heredoc(token, context, &heredoc, &buffer) == REDIR_ERR)
	{
		context->exit_status = 1;
		ret = REDIR_ERR;
	}
	ft_free((void **) &(buffer.str));
	ft_free((void **) &(heredoc.limit));
	ft_putstr_fd(BLUE_BT, STDERR_FILENO);
	return (ret);
}
