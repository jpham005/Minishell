/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:26:23 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "t_lexer.h"
# include "t_token.h"

# define NON_EXPECTED_TOKEN_MESSAGE "syntax error near unexpected token `"
# define NO_MATCH_TOKEN_MESSAGE "syntax error while looking for matching `"

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
