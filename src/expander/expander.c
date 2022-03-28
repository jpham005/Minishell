/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:55:48 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 13:43:47 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	go_side_node(
	t_parse_tree *parse_tree, t_context *context, t_move_direction direction
)
{
	if (direction == RIGHT)
		expander(parse_tree->right, context);
	else if (direction == LEFT)
		expander(parse_tree->left, context);
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
		expand_shell_param(cp, &buffer, context);
		substitute_data(parse_tree, &cp, &buffer);
		if (cp)
		{
			word_split(parse_tree, &cp);
			// expand_asterisk(cp, &buffer);
			// substitute_data(cp, &buffer);
		}
		cp = next;
	}
	ft_free((void **) &(buffer.str));
}

void	expander(t_parse_tree *parse_tree, t_context *context)
{
	if (!parse_tree || !(parse_tree->token) || !(parse_tree->token->data))
		return ;
	parse_tree->original_str = ft_strdup(parse_tree->token->data);
	get_new_token(parse_tree, context);
	go_side_node(parse_tree, context, RIGHT);
	go_side_node(parse_tree, context, LEFT);
}
