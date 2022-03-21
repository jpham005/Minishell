/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_default_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:06:29 by jaham             #+#    #+#             */
/*   Updated: 2022/02/17 15:51:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "libft.h"

int	check_arg(int argc, const char **argv)
{
	int	i;

	i = 1;
	if (argc != 1)
	{
		ft_putstr_fd(TOO_MANY_ARG_ERR_MESSAGE, 2);
		while (argv[i])
		{
			ft_putstr_fd(argv[i++], 2);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (1);
}

int	check_tty(int stdin, int stdout, int stderr)
{
	return (isatty(stdin) && isatty(stdout) && isatty(stderr));
}
