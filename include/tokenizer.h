/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:55:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:31:40 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "t_buffer.h"
# include "t_quote.h"
# include "t_token.h"
# include "t_expand.h"
# include <stddef.h>

// tokenizer
t_token			*tokenizer(const char *str);

// token init destroy
t_token			*init_token(const char *data, t_token_type type);
void			add_token(t_token **head, t_token *new);
void			del_token(t_token **target);
void			clear_token(t_token **head);
void			clear_expanded_list(t_token *token);
void			del_expanded_list(t_expanded_list **head, size_t start);
void			del_tail_token(t_token **target);
t_expanded_list	*init_expanded_list(size_t start, size_t end);
void			add_expanded_list(t_expanded_list **head, t_expanded_list *new);

// token tool
t_token			*get_head_token(t_token *curr);
t_token			*get_tail_token(t_token *head);
size_t			get_token_list_len(t_token *head);
char			**convert_token_to_dptr(t_token *head);

// quote manage
void			check_quote(char c, t_quote_mask *mask);
int				check_quote_mask(t_quote_mask mask);

// tokenizer util
int				is_meta_char(char c);
int				is_double_meta_char(const char *str, size_t start);
int				is_split_condition(char c, t_quote_mask mask);
void			skip_space(const char *str, size_t *start);
void			clear_fd(t_token *token);

#endif
