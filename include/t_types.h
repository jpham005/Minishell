/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_types.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:08:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/11 12:45:42 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TYPES_H
# define T_TYPES_H

# include "t_buffer.h"
# include <termios.h>
# include <stddef.h>

typedef enum e_token_type		t_token_type;
typedef struct termios			t_term;
typedef struct s_term_state		t_term_state;
typedef struct s_envp_list		t_envp_list;
typedef struct s_context		t_context;
typedef enum e_redir_result		t_redir_result;
typedef struct s_heredoc		t_heredoc;
typedef enum e_is_quoted		t_is_quoted;
typedef struct s_redir			t_redir;
typedef enum e_quote_mask		t_quote_mask;
typedef enum e_expand_status	t_expand_status;
typedef struct s_token			t_token;
typedef struct s_expanded_list	t_expanded_list;
typedef enum e_redir_types		t_redir_types;
typedef struct s_parse_tree		t_parse_tree;
typedef enum e_search_result	t_search_result;
typedef enum e_meta_type		t_meta_type;
typedef enum e_move_direction	t_move_direction;
typedef enum e_lexer_result		t_lexer_result;
typedef enum e_lexer_mask		t_lexer_mask;
typedef struct s_lexer_err		t_lexer_err;
typedef enum e_lexer_err_type	t_lexer_err_type;
typedef enum e_nametype			t_nametype;
typedef struct s_filename		t_filename;
typedef enum e_exit_status		t_exit_status;
typedef enum e_cmd_type			t_cmd_type;
typedef enum e_cmd_stat			t_cmd_stat;
typedef struct stat				t_stat;
typedef struct s_pipes			t_pipes;
typedef struct s_pid_list		t_pid_list;

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

enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_FATAL = 1,
	EXIT_ERR = 125,
	PERM = 1,
	NOENT = 2,
	EXIT_SIGNAL = 128,
	STOP_SIGNAL = 17,
	CONTINUE_SIGNAL = 19,
};

enum e_cmd_type
{
	BUILT_IN_CD = 0,
	BUILT_IN_ECHO = 1,
	BUILT_IN_ENV = 2,
	BUILT_IN_EXIT = 3,
	BUILT_IN_EXPORT = 4,
	BUILT_IN_PWD = 5,
	BUILT_IN_UNSET = 6,
	NON_BUILT_IN = 7,
	LOGICAL = 8
};

enum e_cmd_stat
{
	FILE_NOT_FOUND = 0,
	IS_DIR,
	NO_PERMISSION,
	SUCCESS
};

struct s_pipes
{
	char			**cmd;
	t_redir			*redir;
	t_parse_tree	*parse_tree;
	t_pipes			*next;
};

struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

enum e_nametype
{
	FIXED_STR = 0,
	ASTERISK
};

struct s_filename
{
	char		*name;
	char		*checked;
	t_filename	*next;
	t_nametype	type;
};
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

struct s_parse_tree
{
	t_parse_tree	*up;
	t_parse_tree	*left;
	t_parse_tree	*right;
	t_token			*token;
	t_token_type	type;
	t_redir			*redir;
	char			*original_str;
};

enum e_search_result
{
	FOUND = 0,
	NOT_FOUND
};

enum e_meta_type
{
	LOGICAL_META = AND | OR,
	PIPE_META = PIPE,
	REDIRECTION_META = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	NOT_META = 0
};

enum e_move_direction
{
	RIGHT = 0,
	LEFT
};

struct s_term_state
{
	t_term	default_term;
	t_term	rl_term;
};

struct s_envp_list
{
	char				*key;
	char				*value;
	size_t				list_len;
	struct s_envp_list	*next;
};

struct s_context
{
	int				std_fd[3];
	int				exit_status;
	t_envp_list		*envp;
	t_term_state	term_state;
};

struct s_redir
{
	int		in;
	int		out;
	char	*err;
	char	*err_target;
};

enum e_redir_result
{
	REDIR_SUCCESS = 0,
	REDIR_ERR
};

enum e_is_quoted
{
	NOT_QUOTED = 0,
	QUOTED
};

struct s_heredoc
{
	char			*limit;
	t_is_quoted		quoted;
};

enum e_quote_mask
{
	SQUOTE = 1 << 0,
	DQUOTE = 1 << 1
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

enum e_redir_types
{
	REDIR_TYPE = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	REDIR_INS = REDIR_IN | REDIR_HEREDOC,
	REDIR_OUTS = REDIR_OUT | REDIR_APPEND
};

#endif