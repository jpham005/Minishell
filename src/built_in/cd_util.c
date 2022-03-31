/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:28:49 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 14:33:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

void	free_both_cd(char **curr_dir, char **path)
{
	ft_free((void **) curr_dir);
	ft_free((void **) path);
}

void	print_cd_error(char *s1, char *s2)
{
	ft_putstr_fd(SHELL_NAME CD_CMD, STDERR_FILENO);
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(s2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_cd_success(char *s1)
{
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
