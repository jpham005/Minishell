/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:55:48 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 16:01:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expander(t_parse_tree *parse_tree)
{
	if (!parse_tree)
		return ;
	expand_shell_param(parse_tree);
	expand_asterisk(parse_tree);
	go_side_node(parse_tree, RIGHT);
	go_side_node(parse_tree, LEFT);
}
