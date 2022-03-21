/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:34:09 by jaham             #+#    #+#             */
/*   Updated: 2022/03/01 12:47:12 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "envp.h"
#include "libft.h"
#include <stdio.h>

static int	check_valid(const char *key)
{
	if (!ft_isalpha(*key) && *key != '_')
		return (0);
	while (*key)
	{
		if (!ft_isalpha(*key) && !ft_isnum(*key) && *key != '_')
			return (0);
		key++;
	}
	return (1);
}

int	unset(t_context *context, const char **argv)
{
	int		ret_flag;
	size_t	i;

	if (!argv[1])
		return (0);
	ret_flag = 0;
	i = 1;
	while (argv[i])
	{
		if (!check_valid(argv[i]))
		{
			ft_putstr_fd(SHELL_NAME UNSET_CMD, 2);
			ft_putstr_fd("`", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': ", 2);
			ft_putstr_fd(UNSET_ARG_ERR_MESSAGE, 2);
			ret_flag |= 1;
		}
		else
			del_one_envp_list(&(context->envp), argv[i]);
		i++;
	}
	return (ret_flag);
}
