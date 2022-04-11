/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_with_exit_status.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:12:07 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:33:34 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

void	expand_with_exit_status(
	t_token *token, t_buffer *buffer, t_context *context, size_t *i
)
{
	char	*exit_status;
	size_t	start;

	start = *i;
	exit_status = ft_itoa(context->exit_status);
	append_expanded(buffer, exit_status, start, token);
	ft_free((void **) &exit_status);
	(*i) += 2;
}
