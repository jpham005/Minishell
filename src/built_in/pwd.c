/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:47:50 by jaham             #+#    #+#             */
/*   Updated: 2022/02/17 15:31:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdio.h>

int	pwd(t_context *context, const char **argv)
{
	char	*dir;

	if (!context || !argv)
		return (1);
	dir = ft_getcwd(NULL, 1);
	printf("%s\n", dir);
	safe_free((void **) &dir);
	return (0);
}
