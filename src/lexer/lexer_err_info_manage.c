/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_err_info_manage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:37:18 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 21:07:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	init_lexer_err_info(t_lexer_err *err_info)
{
	err_info->data = NULL;
	err_info->type = NO_ERR;
}

void	set_lexer_err_info(
	t_lexer_err *err_info, char *data, t_lexer_err_type type
)
{
	if (err_info->data)
		return ;
	err_info->data = ft_strdup(data);
	err_info->type = type;
}

void	clear_lexer_err_info(t_lexer_err *err_info)
{
	if (err_info->data)
		ft_free((void **) &(err_info->data));
}

void	print_lexer_err(t_lexer_err *err_info)
{
	if (err_info->type == NEAR_TOKEN)
		ft_putstr_fd(MINISHELL_NEAR_TOKEN_ERR_MESSAGE, STDERR_FILENO);
	if (err_info->type == NO_MATCH)
		ft_putstr_fd(MINISHELL_NO_MATCH_ERR_MESSAGE, STDERR_FILENO);
	ft_putstr_fd(err_info->data, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}
