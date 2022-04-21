/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:53:32 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 17:56:54 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HEREDOC_H
# define T_HEREDOC_H

# include "t_quote.h"

typedef struct s_heredoc		t_heredoc;

struct s_heredoc
{
	char			*limit; // cat << eof에서 eof
	t_is_quoted		quoted; // 만약 cat << 'eof'(혹은 "eof") 라면, eof가 limit이지만, heredoc으로 받는 데이터들의 확장이 일어나지 않는다
};

#endif