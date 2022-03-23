/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 17:14:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "terminal.h"

# define EXPORT_CMD "export: "
# define UNSET_CMD "unset: "
# define EXPORT_ARG_ERR_MESSAGE "not a valid identifier\n"
# define UNSET_ARG_ERR_MESSAGE "not a valid identifier\n"

# define EXIT_CMD "exit: "
# define EXIT_NUMERIC (1 << 0)
# define EXIT_NON_NUMERIC (1 << 1)
# define EXIT_NON_NUMERIC_ERR_MESSAGE "numeric argument required\n"
# define EXIT_TOO_MANY_ARG (1 << 2)
# define EXIT_TOO_MANY_ARG_ERR_MESSAGE "too many arguments\n"
# define EXIT_NO_ARG (1 << 3)

# define CD_CMD "cd: "
# define HOME_NOT_SET_ERR_MESSAGE "HOME not set\n"
# define OLDPWD_NOT_SET_ERR_MESSAGE "OLDPWD not set\n"

typedef enum e_sh_built_in
{
	SH_NOT_BUILT_IN = 0,
	SH_CD,
	SH_ECHO,
	SH_ENV,
	SH_EXIT,
	SH_EXPORT,
	SH_PWD,
	SH_UNSET
}	t_sh_built_in;

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

#endif