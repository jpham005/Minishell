/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:23:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/07 16:25:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TREE_H
# define CMD_TREE_H

# include "parser.h"

typedef struct s_cmd_tree	t_cmd_tree;

struct s_cmd_tree
{
	
	t_cmd_tree	*left;
	t_cmd_tree	*right;
};

#endif