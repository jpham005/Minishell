/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_term.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:12:03 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 20:37:44 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TERM_H
# define T_TERM_H

# include <termios.h>

typedef struct termios			t_term;
typedef struct s_term_state		t_term_state;

struct s_term_state
{
	t_term	default_term;
	t_term	rl_term;
};

#endif