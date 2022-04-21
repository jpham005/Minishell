/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_name.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:10:20 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 18:12:31 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NAME_H
# define T_NAME_H


typedef enum e_nametype			t_nametype;
typedef struct s_filename		t_filename;

enum e_nametype
{
	FIXED_STR = 0,
	ASTERISK
};

struct s_filename
{
	char		*name; // 내용 (asdf 거나 ****)
	char		*checked; // 마지막으로 fixed를 찾은 위치 (해당 위치 이후부터 나머지 fixed string을 매칭 시도해야 함)
	t_filename	*next;
	t_nametype	type; // fixed인지 아닌지
};

#endif
