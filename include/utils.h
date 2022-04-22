/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:16:33 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 18:12:39 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types/t_exit.h"
# include "types/t_context.h"

# define PRT_INTRO_ERR_MESSAGE "Print Intro Error\n"
# define SET_TERM_ERR_MESSAGE "Setting Terminal Error\n"
# define ARG_ERR_MESSAGE "Arg Error\n"
# define DEFAULT_FD_ERR_MESSAGE "Default fd Error\n"

void	write_error(const char *str);
void	exit_with_condition(t_exit_condition condition, t_context *context);
int		print_intro(void);

#endif
