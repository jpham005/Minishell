/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 11:15:16 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "tokenizer.h"

# define NON_EXPECTED_TOKEN_MESSAGE "syntax error near unexpected token `"
# define MINISHELL_NEAR_TOKEN_ERR_MESSAGE SHELL_NAME NON_EXPECTED_TOKEN_MESSAGE

# define NO_MATCH_TOKEN_MESSAGE "syntax error while looking for matching `"
# define MINISHELL_NO_MATCH_ERR_MESSAGE SHELL_NAME NO_MATCH_TOKEN_MESSAGE

// lexer
t_lexer_result	lexer(t_token *token);

// lexer err info manage
void			init_lexer_err_info(t_lexer_err *err_info);
void			set_lexer_err_info(t_lexer_err *err_info, \
										char *data, t_lexer_err_type type);
void			clear_lexer_err_info(t_lexer_err *err_info);
void			print_lexer_err(t_lexer_err *err_info);

// check near token err
void			check_near_token_err(t_token *token, t_lexer_err *err_info);

// check near token err util
int				check_prev_token_match(t_token *token, t_lexer_mask mask);
int				check_next_token_match(t_token *token, t_lexer_mask mask);
void			check_syntax_first_token(t_token *token, t_lexer_err *err_info);
void			check_syntax_linked_token(t_token *token, \
														t_lexer_err *err_info);
void			check_syntax_last_token(t_token *type, t_lexer_err *err_info);
void			check_syntax_by_mask(t_token *token, \
									t_lexer_mask mask, t_lexer_err *err_info);

// check special type syntax
void			check_parenthesis_l_syntax(t_token *token, \
														t_lexer_err *err_info);
void			check_parenthesis_r_syntax(t_token *token, \
														t_lexer_err *err_info);

// check match syntax
void			check_match_err(t_token *token, t_lexer_err *err_info);
t_lexer_result	check_match_syntax(t_token *token);
void			check_quote_match_err(t_token *token, t_lexer_err *err_info);

#endif
