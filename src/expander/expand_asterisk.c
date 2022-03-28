/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/28 22:41:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stdio.h>
static void	try_asterisk_expansion(t_token *token)
{
	t_filename	*fixed_data;
	t_filename	*curr_files;

	fixed_data = NULL;
	get_fixed_data(&fixed_data, token);
	printf("\n===================================\n");
	if (!fixed_data)
		printf("null\n");
	for (;fixed_data;fixed_data = fixed_data->next)
		printf("%s\n", fixed_data->name);
	// if (!find_asterisk(&fixed_data))
	// {
	// 	clear_filename(&fixed_data);
	// 	return ;
	// }
	// get_curr_files(&curr_files);
	// perform_asterisk_expansion(token, &fixed_data, &curr_files);
	// clear_filename(&fixed_data);
	// clear_filename(&curr_files);
}

void	expand_asterisk(t_token *token)
{
	t_quote_mask	mask;

	mask = 0;
	while (token)
	{
		try_asterisk_expansion(token);
		token = token->next;
	}
}
