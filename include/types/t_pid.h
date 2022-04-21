/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:16:06 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 20:35:39 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PID_H
# define T_PID_H

# include <stdio.h> 

typedef struct s_pid_list		t_pid_list;

// fork된 프로세스 대기용
struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

#endif
