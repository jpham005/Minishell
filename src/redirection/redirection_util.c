/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:02:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 22:10:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"

int	check_valid_redir_target(t_parse_tree *parse_tree)
{
	return (parse_tree->right \
			&& !(!parse_tree->right->token \
				|| parse_tree->right->token->next \
				|| parse_tree->right->token->data));
}

void	set_redir_err(t_parse_tree *parse_tree, char *target, char *err)
{
	if (!parse_tree->redir->err_target)
		parse_tree->redir->err_target = ft_strdup(target);
	if (!parse_tree->redir->err)
		parse_tree->redir->err = ft_strdup(err);
}

t_redir	*init_redir(void)
{
	t_redir	*ret;

	ret = ft_malloc(sizeof(t_redir), 1);
	ret->in = STDIN_FILENO;
	ret->out = STDOUT_FILENO;
	ret->err = NULL;
	ret->err_target = NULL;
	return (ret);
}

void	destroy_redir(t_redir **redir)
{
	ft_free((void **) &((*redir)->err));
	ft_free((void **) &((*redir)->err_target));
	ft_free((void **) redir);
}

int	is_multiple_redir(t_parse_tree *parse_tree, t_token_type types)
{
	return (parse_tree->up && (parse_tree->up->type & types));
}
