/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_shell_param_expansion.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:50:17 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 02:00:38 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	perform_shell_param_expansion(t_token *token)
{
	t_relative_tokens	relative_tokens;

	get_relative_tokens(&relative_tokens, token);
	
}
