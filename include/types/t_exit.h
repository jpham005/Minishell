/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:11:35 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:09:42 by jaham            ###   ########.fr       */
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

enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_FATAL = 1,
	EXIT_ERR = 125,
	PERM = 1,
	NOENT = 2,
	EXIT_SIGNAL = 128,
	STOP_SIGNAL = 17,
	CONTINUE_SIGNAL = 19,
};

#endif
