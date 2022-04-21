/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:58:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 17:41:15 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PARSE_TREE_H
# define T_PARSE_TREE_H

# include "t_token.h"
# include "t_redir.h"

typedef struct s_parse_tree	t_parse_tree;

struct s_parse_tree
{
	t_parse_tree	*up;
	t_parse_tree	*left;
	t_parse_tree	*right;
	t_token			*token;
	t_token_type	type;
	t_redir			*redir;
	char			*original_str;
};

#endif
