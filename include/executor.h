/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:38:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/03 22:24:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "terminal.h"

typedef enum e_cmd_type	t_cmd_type;

enum e_cmd_type
{
	BUILT_IN_CD = 0,
	BUILT_IN_ECHO = 1,
	BUILT_IN_ENV = 2,
	BUILT_IN_EXIT = 3,
	BUILT_IN_EXPORT = 4,
	BUILT_IN_PWD = 5,
	BUILT_IN_UNSET = 6,
	NON_BUILT_IN = 7
};

// executor
void		executor(t_parse_tree *p_tree, t_context *context);

// executor util
t_cmd_type	get_cmd_type(const char *data);

//execute single cmd
void		execute_single_cmd(t_parse_tree *parse_tree, t_context *context);

//execute bulit_in
int			exec_built_in(t_cmd_type type, t_parse_tree *parse_tree, \
															t_context *context);

#endif