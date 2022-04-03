/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:07:24 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 14:14:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	close_return_pipe(int here_pipe[2])
{
	close(here_pipe[1]);
	return (here_pipe[0]);
}

int	end_heredoc(char **input, int here_pipe[2])
{
	if (!*input)
		set_cursur_heredoc();
	ft_free((void **) input);
	return (close_return_pipe(here_pipe));
}
