/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:39 by jaham             #+#    #+#             */
/*   Updated: 2022/02/22 17:04:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdlib.h>

static char	*make_string(const char **argv, size_t n_op)
{
	size_t	i;
	char	*ret;
	char	*temp;

	ret = ft_strdup("");
	i = n_op + 1;
	while (argv[i])
	{
		temp = ft_strjoin(ret, argv[i]);
		free(ret);
		ret = temp;
		if (argv[i + 1])
		{
			temp = ft_strjoin(ret, " ");
			free(ret);
			ret = temp;
		}
		i++;
	}
	return (ret);
}

static int	write_string(const char *str, size_t n_op)
{
	int	ret;

	ret = write(1, str, ft_strlen(str));
	if (!n_op)
		ret = write(1, "\n", 1);
	return (ret == -1);
}

int	echo(t_context *context, const char **argv)
{
	char	*str;
	int		ret;
	size_t	n_op;

	if (!context)
		return (1);
	if (!argv[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	n_op = !ft_strncmp(argv[1], "-n", 3);
	str = make_string(argv, n_op);
	ret = write_string(str, n_op);
	safe_free((void **) &str);
	return (ret);
}
