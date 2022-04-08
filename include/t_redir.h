/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redir.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:25:46 by jaham             #+#    #+#             */
/*   Updated: 2022/04/08 10:27:12 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_REDIR_H
# define T_REDIR_H

typedef enum e_redir_result	t_redir_result;
typedef struct s_heredoc	t_heredoc;
typedef enum e_is_quoted	t_is_quoted;
typedef struct s_redir			t_redir;

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

#endif