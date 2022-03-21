/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:57:53 by jaham             #+#    #+#             */
/*   Updated: 2022/03/06 16:51:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	exit_with_msg(char *s1, char *s2, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	if (!ft_strchr(s2, '\n'))
		ft_putstr_fd("\n", 2);
	exit(status);
}
