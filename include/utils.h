/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:16:33 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 13:30:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "terminal.h"

# define PRT_INTRO_ERR_MESSAGE "Print Intro Error\n"
# define SET_TERM_ERR_MESSAGE "Setting Terminal Error\n"
# define ARG_ERR_MESSAGE "Arg Error\n"
# define DEFAULT_FD_ERR_MESSAGE "Default fd Error\n"

# define ASCII_ART_PATH "/goinfre/jaham/Minishell/imgs/"

# define END_TERM (1 << 0)
# define ARG_ERR (1 << 1)
# define DEFAULT_FD_ERR (1 << 2)
# define PRINT_INTRO_ERR (1 << 3)

void	write_error(const char *str);
int		exit_with_status(int status, t_context *context);
int		print_intro(void);

#endif
