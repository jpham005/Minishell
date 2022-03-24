/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_near_token_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:01:07 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 13:10:57 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	print_near_token_err(const char *data)
{
	ft_putstr_fd(MINISHELL_NEAR_TOKEN_ERR_MESSAGE, STDERR_FILENO);
	ft_putstr_fd(data, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}

void	print_no_match_err(const char *data)
{
	ft_putstr_fd(MINISHELL_NO_MATCH_ERR_MESSAGE, STDERR_FILENO);
	ft_putstr_fd(data, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}
