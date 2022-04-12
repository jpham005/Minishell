/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:14:54 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 10:17:03 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "terminal.h"
#include "utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_context	context;

	if (!check_arg(argc, (const char **) argv))
		exit_with_condition(ARG_ERR, &context);
	init_shell(&context, (const char **) envp);
	// if (!print_intro())
	// 	exit_with_condition(PRINT_INTRO_ERR, &context);
	readline_loop(&context);
	return (context.exit_status);
}
