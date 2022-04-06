/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/06 18:24:39 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "executor.h"
#include "expander.h"
#include "lexer.h"
#include "libft.h"
#include "redirection.h"
#include "parser.h"
#include "tokenizer.h"
#include "utils.h"
#include <stdlib.h>
#include "tokenizer.h"
#include <stdio.h>
#include <fcntl.h>
void	test_print(t_parse_tree *parse_tree);
void	test_redir(t_parse_tree *parse_tree);
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
t_parse_tree	*testarr[3];
void	readline_loop(t_context *context)
{
	char			*str;
	t_token			*tokenized;
	t_parse_tree	*parse_tree;
	t_pid_list		*pid_list;

	while (1)
	{
		str = ft_readline(context, NULL);
		if (!str)
			exit_with_condition(END_TERM, context);
		if (!check_valid_str(str, context))
		{
			ft_free((void **) &str);
			continue ;
		}
		tokenized = tokenizer(str);
		ft_free((void **) &str);
		if (lexer(tokenized) == LEXER_ERR)
		{
			context->exit_status = SYNTAX_ERR_EXIT_STATUS;
			clear_token(&tokenized);
			continue ;
		}
		// t_token	*cp = tokenized;
		// for (;cp;cp = cp->next)
		// {
		// 	printf("%s\n", cp->data);
		// 	print_type(cp->type);
		// }
		// printf("\no-----------------o\n");
		// printf("!!!TOKENIZER END!!!\n");
		// printf("o-----------------o\n");
		parse_tree = parser(tokenized);
		// test_print(parse_tree);
		// printf("\no--------------o\n");
		// printf("!!!PARSER END!!!\n");
		// printf("o--------------o\n");
		expander(parse_tree, context);
		// test_print(parse_tree);
		// printf("\no----------------o\n");
		// printf("!!!EXPANDER END!!!\n");
		// printf("o----------------o\n");
		pid_list = NULL;
		if (redirection(parse_tree, NULL, context) == REDIR_SUCCESS)
		{
			// test_redir(parse_tree);
			executor(parse_tree, context, &pid_list);
		}
		if (pid_list)
		{
			context->exit_status = get_exit_status(wait_pid_list(pid_list));
			clear_pid_list(&pid_list);
		}
		// for (int i = 6; i < 8200; i++)
		// {
		// 	if (fcntl(i, F_GETFD) == 0)
		// 		printf("fd opend : %d\n", i);
		// }
		destroy_parse_tree(&parse_tree);
		// printf("exit status : %d\n", context->exit_status);
	}
}
