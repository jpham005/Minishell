/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:35:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "lexer.h"
#include "libft.h"
#include "parser.h"
#include "tokenizer.h"
#include "utils.h"

void	readline_loop(t_context *context)
{
	char			*str;
	t_token			*tokenized;
	t_parse_tree	*parse_tree;

	while (1)
	{
		str = ft_readline(context, NULL);
		if (!str)
			exit_with_condition(END_TERM, context);
		if (!check_valid_str(str))
		{
			ft_free((void **) &str);
			continue ;
		}
		tokenized = tokenizer(str, context);
		if (!tokenized)
			continue ;
		ft_free((void **) &str);
		if (lexer(tokenized) == LEXER_ERR)
		{
			context->exit_status = SYNTAX_ERR_EXIT_STATUS;
			clear_token(&tokenized);
			continue ;
		}
		parse_tree = parser(tokenized);
		executor(parse_tree, context);
		clear_parse_tree(&parse_tree);
	}
}
