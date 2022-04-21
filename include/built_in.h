/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 19:52:14 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "t_context.h"

enum e_built_in_exit_status
{
	EXIT_NUMERIC = 1 << 0,
	EXIT_NON_NUMERIC = 1 << 1,
	EXIT_TOO_MANY_ARG = 1 << 2,
	EXIT_NO_ARG = 1 << 3
};

# define EXPORT_CMD "export: "
# define UNSET_CMD "unset: "
# define EXPORT_ARG_ERR_MESSAGE "not a valid identifier\n"
# define UNSET_ARG_ERR_MESSAGE "not a valid identifier\n"

# define EXIT_CMD "exit: "
# define EXIT_NON_NUMERIC_ERR_MESSAGE "numeric argument required\n"
# define EXIT_TOO_MANY_ARG_ERR_MESSAGE "too many arguments\n"

# define CD_CMD "cd: "
# define HOME_NOT_SET_ERR_MESSAGE "HOME not set\n"
# define OLDPWD_NOT_SET_ERR_MESSAGE "OLDPWD not set\n"

int		built_in_exit(t_context *context, const char **argv);
int		export(t_context *context, const char **argv);
int		unset(t_context *context, const char **argv);
int		env(t_context *context, const char **argv);
int		pwd(t_context *context, const char **argv);
int		cd(t_context *context, const char **argv);
void	print_cd_error(char *s1, char *s2);
void	print_cd_success(char *s1);
void	free_both_cd(char **curr_dir, char **path);
int		echo(t_context *context, const char **argv);
int		is_overflow(const char *str);

#endif
