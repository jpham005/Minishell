/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 15:27:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stddef.h>

static int	find_asterisk(t_filename *fixed_data)
{
	while (fixed_data)
	{
		if (fixed_data->type == ASTERISK)
			return (1);
		fixed_data = fixed_data->next;
	}
	return (0);
}

static t_token	*convert_filename_to_token(t_filename *curr_files)
{
	t_token	*ret;

	ret = NULL;
	while (curr_files)
	{
		add_token(&ret, init_token(curr_files->name, WORD));
		curr_files = curr_files->next;
	}
	return (ret);
}

static t_token	*try_asterisk_expansion(t_token *token)
{
	t_filename	*fixed_data;
	t_filename	*curr_files;
	t_token		*ret;

	fixed_data = NULL;
	get_fixed_data(&fixed_data, token);
	curr_files = NULL;
	get_curr_files(&curr_files);
	if (find_asterisk(fixed_data))
		perform_asterisk_expansion(token, fixed_data, &curr_files);
	clear_filename(&fixed_data);
	if (curr_files)
		ret = convert_filename_to_token(curr_files);
	clear_filename(&curr_files);
	return (ret);
}

void	expand_asterisk(t_parse_tree *parse_tree, t_token *token)
{
	t_quote_mask	mask;
	t_token			*new_token;

	mask = 0;
	while (token)
	{
		new_token = try_asterisk_expansion(token);
		if (new_token)
			substitute_token(parse_tree, &token, new_token);
		token = token->next;
	}
}
