/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_context.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:58 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 17:41:12 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CONTEXT_H
# define T_CONTEXT_H

# include <termios.h>
# include <stddef.h>

typedef struct termios			t_term;

typedef struct s_context		t_context;
typedef struct s_envp_list		t_envp_list;
typedef struct s_term_state		t_term_state;

struct s_envp_list
{
	char				*key;
	char				*value;
	size_t				list_len;
	struct s_envp_list	*next;
};

struct s_term_state
{
	t_term	default_term;
	t_term	rl_term;
};

struct s_context
{
	int				std_fd[3];
	int				exit_status;
	t_envp_list		*envp;
	t_term_state	term_state;
};

#endif
