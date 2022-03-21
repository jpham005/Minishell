/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:28:49 by jaham             #+#    #+#             */
/*   Updated: 2022/03/01 12:42:51 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

void	free_both_cd(char **curr_dir, char **path)
{
	safe_free((void **) curr_dir);
	safe_free((void **) path);
}

void	print_cd_error(char *s1, char *s2)
{
	ft_putstr_fd(SHELL_NAME CD_CMD, 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd("\n", 2);
}

void	print_cd_success(char *s1)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd("\n", 2);
}
