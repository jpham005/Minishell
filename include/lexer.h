/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:19 by jaham             #+#    #+#             */
/*   Updated: 2022/03/23 22:23:29 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "terminal.h"
# include "tokenizer.h"

# define NON_EXPECTED_TOKEN_MESSAGE "syntax error near unexpected token `"
# define MINISHELL_SYNTAX_ERR_MESSAGE SHELL_NAME NON_EXPECTED_TOKEN_MESSAGE

typedef enum e_lexer_result	t_lexer_result;
typedef enum e_lexer_mask	t_lexer_mask;

enum e_lexer_result
{
	LEXER_SUCCESS = 0,
	LEXER_ERR
};

enum e_lexer_mask
{
	WORD_PARENTHESIS_COMB_MASK = 0 | PARENTHESIS_L | PARENTHESIS_R,
	REDIR_MASK = 0 | REDIR_IN | REDIR_APPEND | REDIR_OUT | REDIR_APPEND,
	PIPE_MASK = 0 | WORD | PARENTHESIS_R,
	LOGICAL_MASK = 0 | WORD | PARENTHESIS_R,
	MASK_DFL = 0x7FF
};

// lexer
t_lexer_result	check_syntax_err(t_token *token);

// lexer util
int				check_prev_token_match(t_token *token, t_lexer_mask mask);
t_lexer_result	check_word_parenthesis_comb(t_token *token);
t_lexer_result	check_syntax_by_mask(t_token *tkn, t_lexer_mask msk, char *str);

// check by types
t_lexer_result	check_word_syntax(t_token *token);
t_lexer_result	check_redirection_syntax(t_token *token);
t_lexer_result	check_pipe_syntax(t_token *token);

// print syntax err
void			print_syntax_err(const char *data);

#endif