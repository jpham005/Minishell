/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:07:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 22:47:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "libft.h"
#include <fcntl.h>

void	get_redir_in(t_parse_tree *parse_tree)
{
	if (parse_tree->type & REDIR_IN)
	{
		if (check_valid_redir_target(parse_tree->token))
			set_redir_err();
	}
}
