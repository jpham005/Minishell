/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:57:15 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 20:34:45 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXPAND_H
# define T_EXPAND_H

# include <stddef.h>

typedef struct s_expanded_list	t_expanded_list;

struct s_expanded_list
{
	size_t			start;
	size_t			end;
	t_expanded_list	*next;
};

#endif
