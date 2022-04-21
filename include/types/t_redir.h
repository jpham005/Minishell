/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redir.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:53:55 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 17:41:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_REDIR_H
# define T_REDIR_H

typedef struct s_redir	t_redir;

struct s_redir
{
	int		in;
	int		out;
	char	*err;
	char	*err_target;
};

#endif
