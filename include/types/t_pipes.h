/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:57:22 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 17:41:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PIPES_H
# define T_PIPES_H

# include "t_parse_tree.h"
# include "t_redir.h"

typedef struct s_pipes	t_pipes;

struct s_pipes
{
	char			**cmd;
	t_redir			*redir;
	t_parse_tree	*parse_tree;
	t_pipes			*next;
};

#endif
