/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:25:13 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 15:29:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <fcntl.h>

static void	handle_redir_out(t_parse_tree *parse_tree)
{
	if (!check_valid_redir_target(parse_tree))
		
}

static void	hadle_redir_append(t_parse_tree *parse_tree)
{

}

void	get_redir_out(t_parse_tree *parse_tree)
{
	if (parse_tree->type == REDIR_OUT)
		handle_redir_out(parse_tree);
	else if (parse_tree->type == REDIR_APPEND)
		handle_redir_append(parse_tree);
}
