/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_asterisk_expansion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:39:40 by jaham             #+#    #+#             */
/*   Updated: 2022/03/29 20:14:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"

static void	check_first_data(t_filename *fixed_data, t_filename **curr_files)
{
	t_filename	*cp;
	t_filename	*next;

	if (fixed_data->type == ASTERISK)
		return ;
	cp = *curr_files;
	while (cp)
	{
		next = cp->next;
		if (ft_strncmp(cp->name, fixed_data->name, ft_strlen(fixed_data->name)))
			del_one_filename(curr_files, cp);
		else
			cp->checked += ft_strlen(fixed_data->name);
		cp = next;
	}
}

static void	check_linked_fixed(t_filename *fixed_data, t_filename **curr_files)
{
	t_filename	*cp;
	t_filename	*next;
	char		*search_result;

	if (fixed_data->type == ASTERISK)
		return ;
	cp = *curr_files;
	while (cp)
	{
		next = cp->next;
		search_result = \
			ft_strnstr(cp->checked, fixed_data->name, ft_strlen(cp->checked));
		if (!search_result)
			del_one_filename(curr_files, cp);
		else
			cp->checked = search_result + ft_strlen(fixed_data->name);
		cp = next;
	}
}

static int	compare_last(char *checked, char *name)
{
	const size_t	checked_len = ft_strlen(checked);
	const size_t	name_len = ft_strlen(name);
	const size_t	compare_len = ft_min(checked_len, name_len);
	size_t			i;

	i = 0;
	while (i < compare_len)
	{
		if (checked[checked_len - i - 1] != name[name_len - i - 1])
			return (1);
		i++;
	}
	return (0);
}

static void	check_last_data(t_filename *fixed_data, t_filename **curr_files)
{
	t_filename	*cp;
	t_filename	*next;

	if (!fixed_data || fixed_data->type == ASTERISK)
		return ;
	cp = *curr_files;
	while (cp)
	{
		next = cp->next;
		if (compare_last(cp->checked, fixed_data->name))
			del_one_filename(curr_files, cp);
		else
			cp->checked += ft_strlen(fixed_data->name);
		cp = next;
	}
}

void	perform_asterisk_expansion(
	t_filename *fixed_data, t_filename **curr_files
)
{
	check_first_data(fixed_data, curr_files);
	fixed_data = fixed_data->next;
	while (fixed_data && fixed_data->next)
	{
		check_linked_fixed(fixed_data, curr_files);
		fixed_data = fixed_data->next;
	}
	check_last_data(fixed_data, curr_files);
}
