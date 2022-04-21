/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:16:06 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 21:00:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PID_H
# define T_PID_H

# include <unistd.h> 

typedef struct s_pid_list		t_pid_list;

// fork된 프로세스 대기용
struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

#endif
