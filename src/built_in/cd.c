/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:41:42 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:02:59 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "envp.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static char	*try_cdpath(char ***cdpath, const char *arg)
{
	size_t		i;
	struct stat	stat;
	char		*temp;
	char		*path;

	if (!*cdpath)
		return (NULL);
	i = 0;
	path = ft_strjoin("/", arg);
	while ((*cdpath)[i])
	{
		temp = ft_strjoin((*cdpath)[i], path);
		free(path);
		path = temp;
		if (!lstat(path, &stat))
		{
			free_c_dptr(cdpath);
			return (path);
		}
		i++;
	}
	free_c_dptr(cdpath);
	return (NULL);
}

static int	move_to_arg(t_envp_list *envp, const char *arg)
{
	char		**cdpath;
	char		*curr_dir;
	char		*path;
	int			flag;

	cdpath = NULL;
	if (find_list_by_key(envp, "CDPATH"))
		cdpath = ft_split(find_list_by_key(envp, "CDPATH")->value, ":");
	curr_dir = ft_getcwd(NULL, 1);
	path = try_cdpath(&cdpath, arg);
	flag = (path != NULL);
	if (!path)
		path = ft_strdup(arg);
	if (chdir(path) == -1)
	{
		print_cd_error(path, strerror(errno));
		free_both_cd(&curr_dir, &path);
		return (1);
	}
	if (flag)
		print_cd_success(path);
	update_envp_list(&envp, "OLDPWD", curr_dir);
	update_envp_list(&envp, "PWD", path);
	free_both_cd(&curr_dir, &path);
	return (0);
}

static int	move_by_oldpwd(t_envp_list *envp)
{
	t_envp_list	*oldpwd;
	char		*curr_dir;

	oldpwd = find_list_by_key(envp, "OLDPWD");
	if (!oldpwd)
	{
		ft_putstr_fd(OLDPWD_NOT_SET_ERR_MESSAGE, 2);
		return (1);
	}
	curr_dir = ft_getcwd(NULL, 1);
	if (chdir(oldpwd->value) == -1)
	{
		print_cd_error(oldpwd->value, strerror(errno));
		ft_free((void **) &curr_dir);
		return (1);
	}
	print_cd_success(oldpwd->value);
	update_envp_list(&envp, "OLDPWD", curr_dir);
	update_envp_list(&envp, "PWD", oldpwd->value);
	ft_free((void **) &curr_dir);
	return (0);
}

static int	move_to_home(t_envp_list *envp)
{
	t_envp_list	*home;
	char		*curr_dir;

	home = find_list_by_key(envp, "HOME");
	if (!home)
	{
		ft_putstr_fd(HOME_NOT_SET_ERR_MESSAGE, 2);
		return (1);
	}
	curr_dir = ft_getcwd(NULL, 1);
	if (chdir(home->value) == -1)
	{
		print_cd_error(home->value, strerror(errno));
		return (1);
	}
	update_envp_list(&envp, "OLDPWD", curr_dir);
	update_envp_list(&envp, "PWD", home->value);
	ft_free((void **) &curr_dir);
	return (0);
}

int	cd(t_context *context, const char **argv)
{
	if (!argv[1])
		return (move_to_home(context->envp));
	if (!ft_strncmp(argv[1], "-", 2))
		return (move_by_oldpwd(context->envp));
	return (move_to_arg(context->envp, argv[1]));
}
