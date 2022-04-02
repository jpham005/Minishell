/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:20:17 by jaham             #+#    #+#             */
/*   Updated: 2022/04/02 20:22:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <limits.h>

int	is_overflow(const char *str)
{
	int				sign;
	unsigned long	num;

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	sign = 1 - ((*str == '-') << 1);
	str += (*str == '+' || *str == '-');
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > (unsigned long) LONG_MAX / 10 + (sign < 0))
			return (1);
		num *= 10;
		if (num > (unsigned long) LONG_MAX - *str + '0' + (sign < 0))
			return (1);
		num += (*str - '0');
		str++;
	}
	return (0);
}
