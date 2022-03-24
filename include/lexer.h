/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/24 13:22:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "terminal.h"
# include "tokenizer.h"

# define NON_EXPECTED_TOKEN_MESSAGE "syntax error near unexpected token `"
# define MINISHELL_NEAR_TOKEN_ERR_MESSAGE SHELL_NAME NON_EXPECTED_TOKEN_MESSAGE

# define NO_MATCH_TOKEN_MESSAGE "no matching `"
# define MINISHELL_NO_MATCH_ERR_MESSAGE SHELL_NAME NO_MATCH_TOKEN_MESSAGE

typedef enum e_lexer_result		t_lexer_result;
typedef enum e_lexer_mask		t_lexer_mask;

enum e_lexer_result
{
	LEXER_SUCCESS = 0,
	LEXER_ERR
};

enum e_lexer_mask
{
	FIRST_TOKEN_MASK = PIPE | AND | OR | PARENTHESIS_R,
	SPECIAL_ERR_MASK_1 = PARENTHESIS_L | PARENTHESIS_R,
	SPECIAL_ERR_MASK_2 = WORD,
	WORD_MASK = PARENTHESIS_R | WRONG,
	REDIR_MASK = REDIR_IN | REDIR_APPEND | REDIR_OUT | REDIR_APPEND | WRONG,
	PIPE_MASK = WORD | PARENTHESIS_R | WRONG,
	LOGICAL_MASK = WORD | PARENTHESIS_R,
	PARENTHESIS_L_MASK = WORD | PIPE | AND | OR | PARENTHESIS_L,
	PARENTHESIS_R_MASK = WORD | PARENTHESIS_R,
	LAST_TOKEN_MASK = WORD | PARENTHESIS_R,
	MASK_DFL = 0x7FF
};

// lexer
t_lexer_result	lexer(t_token *token);
t_lexer_result	check_near_token_err(t_token *token);
t_lexer_result	check_match_err(t_token *token);

// check word syntax
t_lexer_result	check_word_syntax(t_token *token);
t_lexer_result	check_word_parenthesis_comb(t_token *token);

// lexer util
int				check_prev_token_match(t_token *token, t_lexer_mask mask);
t_lexer_result	check_syntax_first_token(t_token *token);
t_lexer_result	check_syntax_last_token(t_token_type type);
t_lexer_result	check_syntax_by_mask(t_token *tkn, t_lexer_mask msk, char *str);

// print syntax err
void			print_near_token_err(const char *data);
void			print_no_match_err(const char *data);

// check match syntax
t_lexer_result	check_match_syntax(t_token *token);

#endif