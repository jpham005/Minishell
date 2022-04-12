/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 12:41:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "lexer.h"
#include "libft.h"
#include "parser.h"
#include "terminal.h"
#include "tokenizer.h"
#include "utils.h"

static int	get_line(t_context *context, char **line)
{
	*line = ft_readline(context, NULL);
	if (!*line)
		exit_with_condition(END_TERM, context);
	if (!check_valid_str(*line))
	{
		ft_free((void **) line);
		return (0);
	}
	return (1);
}

void	readline_loop(t_context *context)
{
	char			*line;
	t_token			*tokenized;
	t_parse_tree	*parse_tree;

	while (1)
	{
		if (!get_line(context, &line))
			continue ;
		tokenized = tokenizer(line, context);
		if (!tokenized)
			continue ;
		ft_free((void **) &line);
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
