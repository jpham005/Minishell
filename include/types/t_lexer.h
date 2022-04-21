/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:05 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 18:12:34 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEXER_H
# define T_LEXER_H

# include "t_token.h"

typedef enum e_lexer_result		t_lexer_result;
typedef enum e_lexer_mask		t_lexer_mask;
typedef struct s_lexer_err		t_lexer_err;
typedef enum e_lexer_err_type	t_lexer_err_type;

// 렉서 결과
enum e_lexer_result
{
	LEXER_SUCCESS = 0,
	LEXER_ERR
};

// 옆에 올 수 없는 타입들을 모아 둔 마스크
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

// 렉서 에러 출력문에 필요한 에러 타입
enum e_lexer_err_type
{
	NO_ERR = 0,
	NEAR_TOKEN,
	NO_MATCH
};

// 렉서에서 발생한 에러 저장
struct s_lexer_err
{
	char				*data;
	t_lexer_err_type	type;
};


#endif
