/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:12:53 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:09:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_H
# define T_CMD_H

typedef enum e_cmd_type			t_cmd_type;
typedef enum e_cmd_stat			t_cmd_stat;

enum e_cmd_type
{
	BUILT_IN_CD = 0,
	BUILT_IN_ECHO = 1,
	BUILT_IN_ENV = 2,
	BUILT_IN_EXIT = 3,
	BUILT_IN_EXPORT = 4,
	BUILT_IN_PWD = 5,
	BUILT_IN_UNSET = 6,
	NON_BUILT_IN = 7,
	LOGICAL = 8
};

enum e_cmd_stat
{
	FILE_NOT_FOUND = 0,
	IS_DIR,
	NO_PERMISSION,
	SUCCESS
};

#endif
