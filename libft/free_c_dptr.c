/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_c_dptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:38:30 by jaham             #+#    #+#             */
/*   Updated: 2022/03/07 12:26:47 by jaham            ###   ########.fr       */
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
		safe_free((void **) &((*ptr)[i]));
		i++;
	}
	free(*ptr);
	*ptr = NULL;
}
