/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:16:33 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 08:59:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "t_types.h"

# define PRT_INTRO_ERR_MESSAGE "Print Intro Error\n"
# define SET_TERM_ERR_MESSAGE "Setting Terminal Error\n"
# define ARG_ERR_MESSAGE "Arg Error\n"
# define DEFAULT_FD_ERR_MESSAGE "Default fd Error\n"

typedef enum e_exit_condition	t_exit_condition;

enum e_exit_condition
{
	END_TERM = 1 << 0,
	ARG_ERR = 1 << 1,
	DEFAULT_FD_ERR = 1 << 2,
	PRINT_INTRO_ERR = 1 << 3
};

void	write_error(const char *str);
void	exit_with_condition(t_exit_condition condition, t_context *context);
int		print_intro(void);

#endif
