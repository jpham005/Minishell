/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:14:54 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 19:38:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include "utils.h"

static int	check_arg(int argc, char **argv)
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

int	main(int argc, char **argv, char **envp)
{
	t_context	context;

	if (!check_arg(argc, argv))
		exit_with_condition(ARG_ERR, &context);
	shell_init(&context, envp);
	readline_loop(&context);
	return (context.exit_status);
}
