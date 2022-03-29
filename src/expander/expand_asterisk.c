/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 18:05:42 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stddef.h>

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

static t_token	*try_asterisk_expansion(
	t_parse_tree *parse_tree, t_token *token
)
{
	t_filename	*fixed_data;
	t_filename	*curr_files;
	t_token		*ret;

	fixed_data = NULL;
	get_fixed_data(parse_tree, &fixed_data, token);
	if (!fixed_data)
		return (NULL);
	curr_files = NULL;
	get_curr_files(&curr_files);
	perform_asterisk_expansion(fixed_data, &curr_files);
	ret = NULL;
	if (curr_files)
		ret = convert_filename_to_token(curr_files);
	else
		ret = convert_filename_to_token(fixed_data);
	clear_filename(&fixed_data);
	clear_filename(&curr_files);
	return (ret);
}

void	expand_asterisk(t_parse_tree *parse_tree, t_token *token)
{
	t_quote_mask	mask;
	t_token			*next;
	t_token			*new_token;

	mask = 0;
	while (token)
	{
		next = token->next;
		new_token = try_asterisk_expansion(parse_tree, token);
		if (new_token)
			substitute_token(parse_tree, &token, new_token);
		else
			del_token_from_tree(parse_tree, token);
		token = next;
	}
}
