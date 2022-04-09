/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:01:04 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 16:04:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirection.h"

t_redir	*init_redir(int in, int out, char *err, char *err_target)
{
	t_redir	*ret;

	ret = ft_malloc(sizeof(t_redir), 1);
	ret->in = in;
	ret->out = out;
	ret->err = err;
	ret->err_target = err_target;
	return (ret);
}

void	destroy_redir(t_redir **redir)
{
	ft_free((void **) &((*redir)->err));
	ft_free((void **) &((*redir)->err_target));
	ft_free((void **) redir);
}

t_redir	*copy_redir(t_redir *redir)
{
	t_redir	*ret;

	ret = init_redir(redir->in, redir->out, NULL, NULL);
	if (redir->err)
	{
		ret->err = ft_strdup(redir->err);
		ret->err_target = ft_strdup(redir->err_target);
	}
	return (ret);
}
