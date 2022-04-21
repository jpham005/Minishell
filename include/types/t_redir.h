/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redir.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:53:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 18:04:36 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_REDIR_H
# define T_REDIR_H

# include "t_token.h"

typedef enum e_redir_result		t_redir_result;
typedef enum e_redir_types		t_redir_types;
typedef struct s_redir			t_redir;

enum e_redir_result
{
	REDIR_SUCCESS = 0,
	REDIR_ERR
};

enum e_redir_types
{
	REDIR_TYPE = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND, // 리다이렉션
	REDIR_INS = REDIR_IN | REDIR_HEREDOC, // 받는 방향
	REDIR_OUTS = REDIR_OUT | REDIR_APPEND // 나가는 방향
};

struct s_redir
{
	int		in;
	int		out;
	char	*err;
	char	*err_target;
};

#endif
