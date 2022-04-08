/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_split_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:22:25 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 17:12:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static int	is_in_expanded_list(t_expanded_list *expanded_list, size_t index)
{
	while (expanded_list)
	{
		if (is_in_range_index(expanded_list->start, expanded_list->end, index))
			return (1);
		expanded_list = expanded_list->next;
	}
	return (0);
}

void	check_quote_expanded(t_token *token, t_quote_mask *mask, size_t index)
{
	char	checking;

	checking = token->data[index];
	if ((checking == '\'') && (!(*mask & DQUOTE)) \
						&& !is_in_expanded_list(token->expanded_list, index))
		*mask ^= SQUOTE;
	if ((checking == '\"') && (!(*mask & SQUOTE)) \
						&& !is_in_expanded_list(token->expanded_list, index))
		*mask ^= DQUOTE;
}

static void	copy_redir_info(t_token *token, t_token *new_token)
{
	new_token->redir->in = token->redir->in;
	new_token->redir->out = token->redir->out;
	if (token->redir->err)
		new_token->redir->err = ft_strdup(token->redir->err);
	if (token->redir->err_target)
		new_token->redir->err_target = ft_strdup(token->redir->err_target);
}

void	substitute_token(t_parse_tree *parse_tree, t_token **token, \
															t_token *new_token)
{
	t_token	*next;
	t_token	*prev;

	next = (*token)->next;
	prev = (*token)->prev;
	copy_redir_info(*token, new_token);
	del_token(token);
	if (next)
	{
		next->prev = get_tail_token(new_token);
		*token = next;
	}
	if (prev)
	{
		prev->next = get_head_token(new_token);
		*token = prev;
	}
	if (new_token)
	{
		get_tail_token(new_token)->next = next;
		new_token->prev = prev;
		*token = new_token;
	}
	parse_tree->token = get_head_token(*token);
}
