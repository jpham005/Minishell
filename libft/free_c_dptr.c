/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_c_dptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:38:30 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 14:20:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_c_dptr(char ***ptr)
{
	size_t	i;

	if (!*ptr)
		return ;
	i = 0;
	while ((*ptr)[i])
	{
		ft_free((void **) &((*ptr)[i]));
		i++;
	}
	free(*ptr);
	*ptr = NULL;
}
