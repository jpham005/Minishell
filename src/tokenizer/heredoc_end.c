/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:08:52 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 11:09:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"

static int	close_return_pipe(int here_pipe[2])
{
	ft_close(here_pipe[1]);
	return (here_pipe[0]);
}

int	end_heredoc(char **input, int here_pipe[2])
{
	if (!*input)
		set_cursur_heredoc();
	ft_free((void **) input);
	return (close_return_pipe(here_pipe));
}
