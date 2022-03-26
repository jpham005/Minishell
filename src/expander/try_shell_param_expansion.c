/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_shell_param_expansion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:30:20 by jaham             #+#    #+#             */
/*   Updated: 2022/03/26 22:20:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static int	is_envable_char(char c)
{
	return (ft_isalpha(c) || ft_isnum(c) || c == '_' || c == '?');
}

char	*try_get_expansion_str(char *data, t_token *token, t_context *context)
{
	t_quote_mask	mask;


	while (*data)
	{
		check_quote(*data, &mask);
		if ((mask & SQUOTE) && (*data == '$'))
		{
			data++;
			if (is_exit_status_expansion(data))
			{

			}
			while (is_envable_char(*data))
				data++;
		}
		data++;
	}
}

void	preform_expansion(t_token **expanded_token, char *expansion_str)
{

}
