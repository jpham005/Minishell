/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 20:27:33 by jaham            ###   ########.fr       */
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
#include "tokenizer.h"
#include <stdio.h>
void	readline_loop(t_context *context)
{
	char	*str;

	str = ft_readline(context, NULL);
	if (!check_valid_str(str, context))
	{
		ft_free((void **) &str);
		return ; // continue
	}
	t_token	*head = tokenize(str);
	t_token	*cp = head;
	for (;cp;cp = cp->next)
	{
		printf("%s\n", cp->data);
		printf("%d\n", cp->type);
	}
}
