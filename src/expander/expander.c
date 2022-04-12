/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:55:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 16:51:20 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	go_side_node(
	t_parse_tree *parse_tree, t_context *context, t_move_direction dir
)
{
	if (dir == RIGHT)
		parse_tree = parse_tree->right;
	else if (dir == LEFT)
		parse_tree = parse_tree->left;
	if (parse_tree && !((parse_tree->up->type & (AND | OR)) && (dir == RIGHT)))
		expander(parse_tree, context);
}

static void	get_new_token(t_parse_tree *parse_tree, t_context *context)
{
	t_buffer	buffer;
	t_token		*cp;
	t_token		*next;

	cp = parse_tree->token;
	init_t_buffer(&buffer);
	while (cp)
	{
		next = cp->next;
		expand_shell_param(cp, &buffer, context, 0);
		substitute_data(parse_tree, &cp, &buffer);
		if (cp)
			word_split(parse_tree, &cp);
		cp = next;
	}
	ft_free((void **) &(buffer.str));
}

void	expander(t_parse_tree *parse_tree, t_context *context)
{
	if (!parse_tree || !(parse_tree->token) || (parse_tree->type & (AND | OR)))
		return ;
	if (!(parse_tree->token->type & WORD))
	{
		go_side_node(parse_tree, context, LEFT);
		go_side_node(parse_tree, context, RIGHT);
		return ;
	}
	parse_tree->original_str = ft_strdup(parse_tree->token->data);
	get_new_token(parse_tree, context);
	if (!(parse_tree->up && (parse_tree->up->type & REDIR_HEREDOC)))
		expand_asterisk(parse_tree, parse_tree->token);
	go_side_node(parse_tree, context, RIGHT);
	go_side_node(parse_tree, context, LEFT);
}
