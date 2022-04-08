/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:55:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 17:18:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "t_buffer.h"
# include "t_redir.h"
# include "terminal.h"

# define HEREDOC_WRITE_ERR_MESSAGE "write err while heredoc\n"

typedef enum e_quote_mask		t_quote_mask;
typedef enum e_token_type		t_token_type;
typedef enum e_expand_status	t_expand_status;
typedef struct s_token			t_token;
typedef struct s_expanded_list	t_expanded_list;

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

struct s_expanded_list
{
	size_t			start;
	size_t			end;
	t_expanded_list	*next;
};

// tokenizer
t_token			*tokenizer(const char *str, t_context *context);

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

// heredoc
t_redir_result	handle_heredoc(t_token *token, t_context *context);

// heredoc util
void			set_heredoc_info(char *str, t_heredoc *heredoc, \
															t_buffer *buffer);
int				is_heredoc_end(char *input, char *limit);
void			set_cursur_heredoc(void);
void			write_heredoc_string(char *input, int fd);
int				is_heredoc(t_token *token);

// heredoc end
int				end_heredoc(char **input, int here_pipe[2]);

#endif
