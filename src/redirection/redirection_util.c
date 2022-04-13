/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:02:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/13 09:14:57 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"

int	check_valid_redir_target(t_parse_tree *parse_tree)
{
	return (parse_tree->right \
			&& parse_tree->right->token && !parse_tree->right->token->next);
}

void	set_redir_err(t_parse_tree *parse_tree, char *target, char *err)
{
	if (!parse_tree->redir->err)
		parse_tree->redir->err = ft_strdup(err);
	if (!parse_tree->redir->err_target)
		parse_tree->redir->err_target = ft_strdup(target);
}

int	is_multiple_redir(t_parse_tree *parse_tree, t_redir_types types)
{
	return (parse_tree->up && (parse_tree->up->type & (t_token_type) types));
}
