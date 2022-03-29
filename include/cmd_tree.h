/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:59:39 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 22:15:38 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TREE_H
# define CMD_TREE_H

typedef struct s_cmd_tree	t_cmd_tree;
typedef enum e_tree_type	t_tree_type;
typedef struct s_redir		t_redir;
typedef struct s_in_out		t_in_out;
typedef struct s_redir_err	t_redir_err;

struct s_cmd_tree
{
	t_tree_type	type;
	char		**cmd;
	t_redir		*redir;
	t_cmd_tree	*left;
	t_cmd_tree	*right;
};

enum e_tree_type
{
	TREE_AND = 0,
	TREE_OR,
	TREE_PIPE,
	TREE_WRONG,
	TREE_NONE
};

struct s_redir
{
	t_in_out	in_out;
	t_redir_err	err;
};

struct s_in_out
{
	int	in;
	int	out;
};

struct s_redir_err
{
	char	*target;
	char	*err_str;
};

#endif