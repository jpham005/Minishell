/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:58:49 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 01:19:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expander(t_token *token)
{
	expand_shell_param(token);
}
// 1. expand $
// 2. word split ( remove white space, NULL token if non quoted)
// 3. expand *
