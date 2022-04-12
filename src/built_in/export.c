/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:44:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:01:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "envp.h"
#include "libft.h"
#include "terminal.h"
#include <stdio.h>

static int	check_valid(const char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (*str && *str != '=')
	{
		if (!ft_isalpha(*str) && !ft_isnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

static void	exec_normal(t_envp_list *envp, const char *str)
{
	char	*is_op;
	char	*key;
	char	*value;

	is_op = ft_strchr(str, '=');
	if (!is_op)
	{
		key = ft_strdup(str);
		value = NULL;
	}
	else
	{
		key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(is_op));
		value = ft_substr(is_op, 1, ft_strlen(is_op) - 1);
	}
	update_envp_list(&envp, key, value);
	ft_free((void **) &key);
	ft_free((void **) &value);
}

static void	print_export_err_message(const char *str)
{
	ft_putstr_fd(SHELL_NAME EXPORT_CMD, STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putstr_fd(EXPORT_ARG_ERR_MESSAGE, STDERR_FILENO);
}

int	export(t_context *context, const char **argv)
{
	int		ret_flag;
	size_t	i;

	if (!argv[1])
	{
		print_envp(context->envp, SORT);
		return (0);
	}
	ret_flag = 0;
	i = 1;
	while (argv[i])
	{
		if (!check_valid(argv[i]))
		{
			print_export_err_message(argv[i]);
			ret_flag |= 1;
		}
		else
			exec_normal(context->envp, argv[i]);
		i++;
	}
	return (ret_flag);
}
