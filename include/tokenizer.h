/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:55:41 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 21:43:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

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
	WORD = 0,
	REDIR_IN,
	REDIR_HEREDOC,
	REDIR_OUT,
	REDIR_APPEND,
	PIPE,
	PARENTHESIS_L,
	PARENTHESIS_R,
	AND,
	OR
};

enum e_expand_status
{
	NOT_EXPANDED = 0,
	IS_EXPANDED = 1
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
t_token	*tokenize(const char *str);

// token manage
t_token	*init_token(const char *data, t_token_type type);
void	add_token(t_token **head, t_token *new);
void	del_token(t_token **target);
void	clear_token(t_token **head);

// quote manage
void	check_quote(char c, t_quote_mask *mask);
int		check_quote_mask(t_quote_mask mask);

// tokenizer util
int		is_split_condition(char c, t_quote_mask mask);
int		is_break_condition(char *str, size_t *end);
void	skip_space(const char *str, size_t *start);

#endif