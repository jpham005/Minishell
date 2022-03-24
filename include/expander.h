/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:59:05 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 01:56:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANEDER_H

# include "tokenizer.h"

typedef struct s_relative_tokens	t_relative_tokens;

struct s_relative_tokens
{
	t_token	*prev;
	t_token *curr;
	t_token	*next;
};

// expand shell param
void	expand_shell_param(t_token *token);

// perform shell param expansion
void	perform_shell_param_expansion(t_token *token);

// manage relative tokens
void	get_relative_tokens(t_relative_tokens *relative_tokens, t_token *token);
void	append_new_tokens(t_relative_tokens *relative_tokens, t_token *token);

#endif