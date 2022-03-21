/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_by_errno.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:04:51 by jaham             #+#    #+#             */
/*   Updated: 2022/02/25 17:47:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>
// strerror?
void	exit_by_errno(int status, char *cmd)
{
	if (status == EACCES)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		write(2, "not executable\n", ft_strlen("not executable\n"));
		exit(126);
	}
	if (status == ENOENT)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		write(2, "command not found\n", ft_strlen("command not found\n"));
		exit(127);
	}
	exit(126);
}
