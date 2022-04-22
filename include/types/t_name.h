/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_name.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:10:20 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/22 18:13:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NAME_H
# define T_NAME_H

typedef enum e_nametype			t_nametype;
typedef struct s_filename		t_filename;

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

#endif
