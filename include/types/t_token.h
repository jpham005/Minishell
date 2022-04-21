/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:48:03 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 18:04:42 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "t_redir.h"
# include "t_expand.h"
# include <stddef.h>

typedef enum e_token_type		t_token_type;
typedef struct s_token			t_token;

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
