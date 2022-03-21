/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 22:31:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
// #include "exec.h"
#include "libft.h"
// #include "parser.h"
#include "utils.h"
#include <stdlib.h>

void	handle_syntax_err(t_context *context)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(SYNTAX_ERR_MESSAGE, 2);
	context->exit_status = 258;
}

void	readline_loop(t_context *context)
{
	char	*str;

	str = ft_readline(context, NULL);
}
