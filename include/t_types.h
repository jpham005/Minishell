/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_types.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:08:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 17:40:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TYPES_H
# define T_TYPES_H

# include "t_buffer.h"
# include <termios.h>
# include <stddef.h>

// typedef enum e_token_type		t_token_type;
// typedef struct termios			t_term;
// typedef struct s_term_state		t_term_state;
// typedef struct s_envp_list		t_envp_list;
// typedef struct s_context		t_context;
typedef enum e_redir_result		t_redir_result;
typedef struct s_heredoc		t_heredoc;
typedef enum e_is_quoted		t_is_quoted;
// typedef struct s_redir			t_redir;
typedef enum e_quote_mask		t_quote_mask;
typedef enum e_expand_status	t_expand_status;
// typedef struct s_token			t_token;
// typedef struct s_expanded_list	t_expanded_list;
typedef enum e_redir_types		t_redir_types;
// typedef struct s_parse_tree		t_parse_tree;
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
// typedef struct s_pipes			t_pipes;
typedef struct s_pid_list		t_pid_list;

// 토큰 종류, 트리에서도 사용
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

// exit status 용 변수들. 상황별로 정해져 있음
enum e_exit_status
{
	EXIT_SUCCESS = 0,
	EXIT_REDIR_ERR = 1,
	EXIT_FATAL = 1,
	EXIT_ERR = 125,
	PERM = 1, // 파일 존재하나 권한이 없을 때
	NOENT = 2, // 파일 미존재 (엔트리 없을 때)
	EXIT_SIGNAL = 128, // 시그널 종료 시 128 + 시그널 넘버
	STOP_SIGNAL = 17, // stop , cont는 특별 케이스
	CONTINUE_SIGNAL = 19,
};

// 빌트인 7개 + 빌트인 아닐 때 + 논리 연산자 일 때 (해당 경우 executor 재귀 호출)
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

// (쉘에서 에러 메세지가 다르게 나오는 경우 예외처리)
enum e_cmd_stat
{
	FILE_NOT_FOUND = 0, // bash : asdf/asdf
	IS_DIR, // bash : dir
	NO_PERMISSION, // chmod 000, bash : no_perm_file
	SUCCESS
};

// 실행용 파이프로 묶인 명령어 목록
struct s_pipes
{
	char			**cmd; // 실행할 명령어 + 인자
	t_redir			*redir; // 해당 명령어에 대한 리다이렉션 (<, <<, >, >>)
	t_parse_tree	*parse_tree; // AND, OR일 경우 따로 만들지 않고 parse_tree 그대로 저장
	t_pipes			*next;
};

// fork된 프로세스 대기용
struct s_pid_list
{
	pid_t		pid;
	t_pid_list	*next;
};

// * 확장 시 고정된 스트링인지, 확장을 실행하는 *나 *****들인지 나타냄
enum e_nametype
{
	FIXED_STR = 0,
	ASTERISK
};

struct s_filename
{
	char		*name; // 내용 (asdf 거나 ****)
	char		*checked; // 마지막으로 fixed를 찾은 위치 (해당 위치 이후부터 나머지 fixed string을 매칭 시도해야 함)
	t_filename	*next;
	t_nametype	type; // fixed인지 아닌지
};

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

struct s_parse_tree
{
	t_parse_tree	*up; // 부모
	t_parse_tree	*left;
	t_parse_tree	*right;
	t_token			*token; // 토큰 리스트, echo->a->b->c->d 처럼 들어감. 메타 캐릭터의 경우 하나만 있음 (&&, ||, |, >, <, <<, >>)
	t_token_type	type; // 트리의 타입, 토큰 타입을 그대로 가져와서 쓸 수 있음
	t_redir			*redir; // 트리의 리다이렉션, (ls && ls) > outfile 
							// 위의 경우 ls 두개가 모두 outfile로 가야하기 때문에, 기본적으로 트리는 하위 노드에 리다이렉션 정보를 상속해야 함.
	char			*original_str; // 에러 메세지 맞추기용 확장 전 스트링
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

// 노드 순회 방향
enum e_move_direction
{
	RIGHT = 0,
	LEFT
};

// readline용 ECHOCTL 끈 터미널과 그렇지 않은 터미널 저장
struct s_term_state
{
	t_term	default_term;
	t_term	rl_term;
};

// 환경변수
struct s_envp_list
{
	char				*key; // PATH
	char				*value; // /usr/bin:/usr/local/bin
	size_t				list_len; // 환경변수 길이
	struct s_envp_list	*next;
};

// 필요한 모든 정보 들고 다니기
struct s_context
{
	int				std_fd[3]; // 실행 시 복구용 터미널 fd (built in 명령어가 부모 프로세스에서 실행 될 경우 사용)
	int				exit_status; // 직전 명령어의 종료 상태 (and, or가 참조함)
	t_envp_list		*envp; // 환경변수
	t_term_state	term_state; // readline관련 터미널 정보
};

// 리다이렉션 정보
struct s_redir
{
	int		in; // <, <<의 경우 파일의 fd 저장
	int		out; // >, >>, "
	char	*err; // 에러 메세지, 만약 리다이렉션 중 에러가 있었을 경우 저장, 아니면 NULL
	char	*err_target; // 에러 타겟, "
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
	char			*limit; // cat << eof에서 eof
	t_is_quoted		quoted; // 만약 cat << 'eof'(혹은 "eof") 라면, eof가 limit이지만, heredoc으로 받는 데이터들의 확장이 일어나지 않는다
};

enum e_quote_mask
{
	SQUOTE = 1 << 0,
	DQUOTE = 1 << 1
};

// 문장의 가장 작은 단위
struct s_token
{
	char			*data; // 데이터 (echo, |, etc)
	t_token_type	type; // 타입 (WORD, PIPE, etc)
	t_expanded_list	*expanded_list; // 확장 단계에서 사용, 토큰 나눌 땐 안씀. 확장의 결과물로 나온 따옴표들은 유지되어야 하기 때문에 필요
	t_token			*next;
	t_token			*prev; // 수정 용이하게 양방향으로 만듦
	t_redir			*redir; // 리다이렉션 단계에서 사용, heredoc 때문에 미리 들고 있어야 함
};

struct s_expanded_list
{
	size_t			start; // 확장 후 string에서 확장이 시작된 위치. s$USER->sjaham 이라면 j가 확장이 시작된 위치이다.
	size_t			end; // " 끝난 위치
	t_expanded_list	*next; // 한 string에도 여러번 확장이 있었을 가능성이 있다
};

enum e_redir_types
{
	REDIR_TYPE = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND, // 리다이렉션
	REDIR_INS = REDIR_IN | REDIR_HEREDOC, // 받는 방향
	REDIR_OUTS = REDIR_OUT | REDIR_APPEND // 나가는 방향
};

#endif