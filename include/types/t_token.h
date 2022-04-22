/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:48:03 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 18:10:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "t_expand.h"
# include "t_redir.h"
# include <stddef.h>

typedef enum e_token_type			t_token_type;
typedef enum e_token_redir_types	t_token_redir_types;
typedef struct s_token				t_token;

enum e_token_type
{
	WORD = 1 << 0,
	REDIR_IN = 1 << 1,
	REDIR_HEREDOC = 1 << 2,
	REDIR_OUT = 1 << 3,
	REDIR_APPEND = 1 << 4,
	PIPE = 1 << 5,
	PARENTHESIS_L = 1 << 6,
	PARENTHESIS_R = 1 << 7,
	AND = 1 << 8,
	OR = 1 << 9,
	WRONG = 1 << 10,
	UNQUOTED = 1 << 11
};

enum e_token_redir_types
{
	REDIR_TYPE = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	REDIR_INS = REDIR_IN | REDIR_HEREDOC,
	REDIR_OUTS = REDIR_OUT | REDIR_APPEND
};

struct s_token
{
	char			*data;
	t_token_type	type;
	t_expanded_list	*expanded_list;
	t_token			*next;
	t_token			*prev;
	t_redir			*redir;
};

#endif
