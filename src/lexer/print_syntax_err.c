/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:01:07 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 19:35:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	print_syntax_err(const char *data)
{
	if (data)
	{
		ft_putstr_fd(MINISHELL_SYNTAX_ERR_MESSAGE, STDERR_FILENO);
		ft_putstr_fd(data, STDERR_FILENO);
		ft_putstr_fd("\'\n", 2);
	}
}
