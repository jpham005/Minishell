/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:03:05 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:35:39 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "libft.h"
#include <stdio.h>
#include <readline/history.h>

static int	is_valid_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_str(const char *str)
{
	char	**splited;
	int		ret;
	size_t	i;

	if (!*str)
		return (0);
	splited = ft_split(str, " \t\n");
	ret = 0;
	i = 0;
	while (splited[i])
	{
		if (is_valid_str(splited[i]))
		{
			ret = 1;
			break ;
		}
		i++;
	}
	free_c_dptr(&splited);
	add_history(str);
	return (ret);
}
