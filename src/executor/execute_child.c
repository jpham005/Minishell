/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/09 14:13:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static t_cmd_stat	get_cmd_stat(const char *data)
{
	t_stat	stat;

	if (lstat(data, &stat) == -1)
		return (FILE_NOT_FOUND);
	if (stat.st_mode & S_IFDIR)
		return (IS_DIR);
	if (!(stat.st_mode & S_IXUSR))
		return (NO_PERMISSION);
	return (SUCCESS);
}

static void	execute_with_user_path(t_parse_tree *parse_tree, t_context *context)
{
	int				stat;
	t_token * const	token = parse_tree->token;

	stat = get_cmd_stat(token->data);
	if (stat == FILE_NOT_FOUND)
		exit_with_msg(token->data, NOT_FOUND_MESSAGE, EXIT_ERR + NOENT);
	if (stat == IS_DIR)
		exit_with_msg(token->data, IS_DIR_MESSAGE, EXIT_ERR + PERM);
	if (stat == NO_PERMISSION)
		exit_with_msg(token->data, NO_PERMISSION_MESSAGE, EXIT_ERR + PERM);
	execve(token->data, convert_token_to_dptr(token), \
										convert_envp_to_dptr(context->envp));
	exit_with_msg(token->data, strerror(errno), EXIT_ERR + errno);
}

static char	*find_cmd_from_path(
	const char *data, t_context *context, t_envp_list *path_list
)
{
	char		**path;
	char		*ret;
	char		*temp;
	t_stat		stat;
	
	if (!data[0])
		return (NULL);
	path = ft_split(path_list->value, ":");
	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		ret = ft_strjoin(temp, data);
		if (lstat(ret, &stat) != -1)
		{
			ft_free((void **) &temp);
			break ;
		}
		ft_free((void **) &temp);
		ft_free((void **) &ret);
		path++;
	}
	return (ret);
}

static void	execute_with_envp_path(
	t_parse_tree *parse_tree, t_context *context, t_envp_list *path_list
)
{
	char	*cmd;

	cmd = find_cmd_from_path(parse_tree->token->data, context, path_list);
	if (!cmd)
		exit_with_msg(parse_tree->token->data, CMD_NOT_FOUND_MESSAGE, \
															EXIT_ERR + NOENT);
	execve(cmd, convert_token_to_dptr(parse_tree->token), \
										convert_envp_to_dptr(context->envp));
	exit_with_msg(parse_tree->token->data, strerror(errno), EXIT_ERR + errno);
}

void	execute_child(t_parse_tree *parse_tree, t_context *context)
{
	t_envp_list	*path_list;

	set_sig_handler_child();
	if (!parse_tree->token)
		ft_exit(0);
	path_list = find_list_by_key(context->envp, "PATH");
	if (ft_strchr(parse_tree->token->data, '/') || !path_list)
		execute_with_user_path(parse_tree, context);
	else
		execute_with_envp_path(parse_tree, context, path_list);
}
