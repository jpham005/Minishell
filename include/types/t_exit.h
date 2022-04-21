/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:11:35 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 20:32:30 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXIT_H
# define T_EXIT_H

typedef enum e_exit_status		t_exit_status;
typedef enum e_exit_condition	t_exit_condition;

enum e_exit_condition
{
	END_TERM = 1 << 0,
	ARG_ERR = 1 << 1,
	DEFAULT_FD_ERR = 1 << 2,
	PRINT_INTRO_ERR = 1 << 3
};

// exit status 용 변수들. 상황별로 정해져 있음
enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_FATAL = 1,
	EXIT_ERR = 125,
	PERM = 1, // 파일 존재하나 권한이 없을 때
	NOENT = 2, // 파일 미존재 (엔트리 없을 때)
	EXIT_SIGNAL = 128, // 시그널 종료 시 128 + 시그널 넘버
	STOP_SIGNAL = 17, // stop , cont는 특별 케이스
	CONTINUE_SIGNAL = 19,
};

#endif
