/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 13:18:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
// #include "exec.h"
#include "lexer.h"
#include "libft.h"
// #include "parser.h"
#include "tokenizer.h"
#include "utils.h"
#include <stdlib.h>

#include "tokenizer.h"
#include <stdio.h>
void	print_type(size_t type)
{
	size_t	i;

	char *type_str[] = {
		"WORD",
		"REDIR_IN",
		"REDOR_HEREDOC",
		"REDIR_OUT",
		"REDIR_APPEND",
		"PIPE",
		"PARENTHESIS_L",
		"PARENTHESIS_R",
		"AND",
		"OR",
		"WRONG"
	};
	i = 1;
	int cnt = 0;
	while (i != type)
	{
		i <<= 1;
		cnt++;
	}
	printf("%s\n", type_str[cnt]);
}

void	readline_loop(t_context *context)
{
	char	*str;
	t_token	*tokenized;

	while (1)
	{
		str = ft_readline(context, NULL);
		if (!str)
			exit(exit_with_status(END_TERM, context));
		if (!check_valid_str(str, context))
		{
			ft_free((void **) &str);
			continue ;
		}
		tokenized = tokenize(str);
		ft_free((void **) &str);
		if (lexer(tokenized) == LEXER_ERR)
		{
			context->exit_status = SYNTAX_ERR_EXIT_STATUS;
			clear_token(&tokenized);
			continue ;
		}
		context->exit_status = 0;
		t_token	*cp = tokenized;
		for (;cp;cp = cp->next)
		{
			printf("%s\n", cp->data);
			print_type(cp->type);
		}
		clear_token(&tokenized);
	}
}
