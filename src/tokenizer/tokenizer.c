/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:48:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/12 19:27:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"

static void	get_token_word(t_token **head, const char *str, size_t *start)
{
	t_quote_mask	mask;
	size_t			end;
	char			*data;

	mask = 0;
	end = *start;
	while (!is_split_condition(str[end], mask))
	{
		check_quote(str[end], &mask);
		end++;
	}
	if (end == (*start))
		return ;
	data = ft_substr(str, *start, end - (*start));
	add_token(head, init_token(data, WORD));
	ft_free((void **) &data);
	*start = end;
}

static t_token_type	get_meta_type(char *data)
{
	if (ft_iseq(data, "<"))
		return (REDIR_IN);
	if (ft_iseq(data, ">"))
		return (REDIR_OUT);
	if (ft_iseq(data, ">>"))
		return (REDIR_APPEND);
	if (ft_iseq(data, "<<"))
		return (REDIR_HEREDOC);
	if (ft_iseq(data, "|"))
		return (PIPE);
	if (ft_iseq(data, "||"))
		return (OR);
	if (ft_iseq(data, "&"))
		return (WRONG);
	if (ft_iseq(data, "&&"))
		return (AND);
	if (ft_iseq(data, "("))
		return (PARENTHESIS_L);
	if (ft_iseq(data, ")"))
		return (PARENTHESIS_R);
	return (WRONG);
}

static void	get_token_meta(t_token **head, const char *str, size_t *start)
{
	size_t	end;
	char	*data;

	if (!is_meta_char(str[*start]))
		return ;
	end = *start + 1;
	if (is_double_meta_char(str, *start))
		end++;
	data = ft_substr(str, *start, end - (*start));
	add_token(head, init_token(data, get_meta_type(data)));
	ft_free((void **) &data);
	*start = end;
}

t_token	*tokenizer(const char *str, t_context *context)
{
	t_token	*head;
	size_t	start;

	head = NULL;
	start = 0;
	while (str[start])
	{
		get_token_word(&head, str, &start);
		if (is_heredoc(head) \
			&& (handle_heredoc(get_tail_token(head), context) == REDIR_ERR))
		{
			clear_fd(head);
			clear_token(&head);
			break ;
		}
		skip_space(str, &start);
		get_token_meta(&head, str, &start);
	}
	return (head);
}
