/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_context.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:58 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:41:54 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CONTEXT_H
# define T_CONTEXT_H

# include "t_envp.h"
# include "t_term.h"

typedef struct s_context		t_context;

struct s_context
{
	int				std_fd[3];
	int				exit_status;
	t_envp_list		*envp;
	t_term_state	term_state;
};

#endif
