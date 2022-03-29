/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:59:59 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 22:16:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_tree.h"
#include "redirection.h"

t_tree_type	get_tree_type(t_parse_tree *parse_tree)
{
	if ((parse_tree->type \
		& (REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND)))
	{
		if (is_wrong_redir(parse_tree))
			return (TREE_WRONG);
		return (TREE_NONE);
	}
	if (parse_tree->type == PIPE)
		return (TREE_PIPE);
	if (parse_tree->type == AND)
		return (TREE_AND);
	if (parse_tree->type == OR)
		return (TREE_OR);
}
