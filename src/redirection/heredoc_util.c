/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/01 21:56:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"

int	is_heredoc_end(char *input, char *limit)
{
	return (!input || !ft_strncmp(input, limit, ft_strlen(limit) + 1));
}

void	set_heredoc_info(char *str, t_heredoc *heredoc, t_buffer *buffer)
{
	t_quote_mask	mask;
	size_t			i;

	mask = 0;
	i = 0;
	while (str[i])
	{
		if (check_quote_mask(mask) || (str[i] != '\'' && str[i] != '\"'))
			append_t_buffer(buffer, str[i]);
		check_quote(str[i], &mask);
		i++;
	}
	heredoc->limit = get_t_buffer_string(buffer);
	if (ft_strchr(str, '\'' || ft_strchr(str, '\"')))
		heredoc->quoted = QUOTED;
	else
		heredoc->quoted = NOT_QUOTED;
}
