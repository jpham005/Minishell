/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:54:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 11:01:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "lexer.h"
#include "heredoc.h"
#include "libft.h"
#include "parser.h"
#include "terminal.h"
#include "tokenizer.h"

void	readline_loop(t_context *context)
{
	char			*line;
	t_token			*tokenized;
	t_parse_tree	*parse_tree;

	while (1)
	{
		if (!get_line(context, &line))
			continue ;
		tokenized = analize_line(line, context);
		ft_free((void **) &line);
		if (!tokenized)
			continue ;
		if (!heredoc(tokenized, context))
		{
			handle_heredoc_err(&tokenized);
			continue ;
		}
		parse_tree = parser(tokenized);
		executor(parse_tree, context);
		clear_parse_tree(&parse_tree);
	}
}
