/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:53:32 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:09:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HEREDOC_H
# define T_HEREDOC_H

# include "t_quote.h"

typedef struct s_heredoc		t_heredoc;

struct s_heredoc
{
	char			*limit;
	t_is_quoted		quoted;
};

#endif