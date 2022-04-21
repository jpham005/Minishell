/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redir.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:53:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 21:07:52 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_REDIR_H
# define T_REDIR_H

typedef enum e_redir_result		t_redir_result;
typedef struct s_redir			t_redir;

enum e_redir_result
{
	REDIR_SUCCESS = 0,
	REDIR_ERR
};

struct s_redir
{
	int		in;
	int		out;
	char	*err;
	char	*err_target;
};

#endif
