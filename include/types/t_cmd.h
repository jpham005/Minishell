/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:12:53 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 18:18:18 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_H
# define T_CMD_H

typedef enum e_cmd_type			t_cmd_type;
typedef enum e_cmd_stat			t_cmd_stat;

// 빌트인 7개 + 빌트인 아닐 때 + 논리 연산자 일 때 (해당 경우 executor 재귀 호출)
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

// (쉘에서 에러 메세지가 다르게 나오는 경우 예외처리)
enum e_cmd_stat
{
	FILE_NOT_FOUND = 0, // bash : asdf/asdf
	IS_DIR, // bash : dir
	NO_PERMISSION, // chmod 000, bash : no_perm_file
	SUCCESS
};

#endif
