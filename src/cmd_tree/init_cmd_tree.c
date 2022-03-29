/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:11:38 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 21:50:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_tree.h"
#include "libft.h"

t_cmd_tree	*init_cmd_tree(t_tree_type type, char **cmd, t_redir *redir)
{
	t_cmd_tree	*ret;

	ret = ft_malloc(sizeof(t_cmd_tree), 1);
	ret->type = type;
	ret->cmd = cmd;
	ret->redir = redir;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
