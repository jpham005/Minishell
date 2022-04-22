/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:05 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:13:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEXER_H
# define T_LEXER_H

# include "t_token.h"

typedef enum e_lexer_result		t_lexer_result;
typedef enum e_lexer_mask		t_lexer_mask;
typedef struct s_lexer_err		t_lexer_err;
typedef enum e_lexer_err_type	t_lexer_err_type;

enum e_lexer_result
{
	LEXER_SUCCESS = 0,
	LEXER_ERR
};

enum e_lexer_mask
{
	FIRST_TOKEN_MASK = PIPE | AND | OR | PARENTHESIS_R,
	WORD_MASK = PARENTHESIS_R | WRONG,
	REDIR_MASK = REDIR_IN | REDIR_APPEND | REDIR_OUT | REDIR_APPEND | WRONG,
	PIPE_MASK = WORD | PARENTHESIS_R | WRONG,
	LOGICAL_MASK = WORD | PARENTHESIS_R,
	PARENTHESIS_L_MASK = PIPE | AND | OR | PARENTHESIS_L,
	PARENTHESIS_R_MASK = WORD | PARENTHESIS_R,
	LAST_TOKEN_MASK = WORD | PARENTHESIS_R,
	MASK_DFL = 0x7FF
};

enum e_lexer_err_type
{
	NO_ERR = 0,
	NEAR_TOKEN,
	NO_MATCH
};

struct s_lexer_err
{
	char				*data;
	t_lexer_err_type	type;
};

#endif
