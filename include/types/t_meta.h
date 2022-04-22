/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_meta.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:07:16 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:12:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_META_H
# define T_META_H

# include "t_token.h"

typedef enum e_meta_type	t_meta_type;

enum e_meta_type
{
	LOGICAL_META = AND | OR,
	PIPE_META = PIPE,
	REDIRECTION_META = REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND,
	NOT_META = 0
};

#endif
