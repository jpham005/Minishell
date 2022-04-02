/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 22:12:52 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "redirection.h"

int	is_heredoc_end(char *input, char *limit)
{
	return (!input || !ft_strncmp(input, limit, ft_strlen(limit) + 1) || \
														make_sigint_static(-1));
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

int	write_heredoc_string(char *input, int fd)
{
	return ((ft_putstr_fd(input, fd) != -1) && (ft_putstr_fd("\n", fd) != -1));
}
