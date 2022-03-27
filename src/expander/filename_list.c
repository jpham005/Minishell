/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:04 by jaham             #+#    #+#             */
/*   Updated: 2022/03/27 17:41:23 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

t_filename	*init_filename(char *filename)
{
	t_filename	*ret;

	ret = ft_malloc(sizeof(t_filename), 1);
	ret->name = ft_strdup(filename);

}
