/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:55:41 by jaham             #+#    #+#             */
/*   Updated: 2022/03/25 11:35:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <sys/types.h>

typedef enum e_quote_mask		t_quote_mask;
typedef enum e_token_type		t_token_type;
typedef enum e_expand_status	t_expand_status;
typedef struct s_token			t_token;

enum e_quote_mask
{
	SQUOTE = 1 << 0,
	DQUOTE = 1 << 1
};

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
	WRONG = 1 << 10
};

enum e_expand_status
{
	NOT_EXPANDED = 0,
	QUOTE_REMOVED
};

struct s_token
{
	char			*data;
	t_token_type	type;
	t_expand_status	expand_stat;
	t_token			*next;
	t_token			*prev;
};

// tokenizer
t_token			*tokenize(const char *str);

// token manage
t_token			*init_token(const char *data, t_token_type type);
void			add_token(t_token **head, t_token *new);
void			del_token(t_token **target);
void			clear_token(t_token **head);

// get token
t_token			*get_head_token(t_token *curr);
t_token			*get_tail_token(t_token *head);

// quote manage
void			check_quote(char c, t_quote_mask *mask);
int				check_quote_mask(t_quote_mask mask);

// tokenizer util
int				is_meta_char(char c);
int				is_double_meta_char(const char *str, size_t start);
int				is_split_condition(char c, t_quote_mask mask);
void			skip_space(const char *str, size_t *start);

#endif