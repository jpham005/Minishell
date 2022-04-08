/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:36:14 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 13:55:34 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "tokenizer.h"

int	is_heredoc_end(char *input, char *limit)
{
	return (!input || ft_iseq(input, limit));
}

void	set_heredoc_info(char *str, t_heredoc *heredoc, t_buffer *buffer)
{
	t_quote_mask	mask;
	size_t			i;

	mask = 0;
	i = 0;
	while (str[i])
	{
		check_quote(str[i], &mask);
		if (!is_valid_quote(str[i], NULL, i, &mask))
			append_t_buffer(buffer, str[i]);
		i++;
	}
	heredoc->limit = get_t_buffer_string(buffer);
	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		heredoc->quoted = QUOTED;
	else
		heredoc->quoted = NOT_QUOTED;
}

void	set_cursur_heredoc(void)
{
	ft_putstr_fd("\033[1A", 1);
	ft_putstr_fd("\033[2C", 1);
}

void	write_heredoc_string(char *input, int fd)
{
	if ((ft_putstr_fd(input, fd) == -1) || (ft_putstr_fd("\n", fd) == -1))
		ft_exit(1);
}

int	is_heredoc(t_token *token)
{
	t_token	*target;

	if (!token)
		return (0);
	target = get_tail_token(token);
	return (target && (target->type == WORD) && target->prev \
			&& (target->prev->type == REDIR_HEREDOC));
}
