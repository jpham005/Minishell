/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:03:06 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 17:12:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include <dirent.h>

void	get_curr_files(t_filename **curr_files)
{
	char			*curr_dir;
	DIR				*dir_stream;
	struct dirent	*curr_file;

	curr_dir = getcwd(NULL, 0);
	dir_stream = opendir(curr_dir);
	ft_free((void **) &curr_dir);
	curr_file = readdir(dir_stream);
	while (curr_file)
	{
		if (curr_file->d_name[0] != '.')
			add_filename(curr_files, curr_file->d_name, FIXED_STR);
		curr_file = readdir(dir_stream);
	}
	closedir(dir_stream);
}