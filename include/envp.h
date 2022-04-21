/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:18 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 20:53:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "types/t_envp.h"

enum e_print_op
{
	SORT = 1 << 0,
	UNSORT = 1 << 1
};

int			init_envp_list(t_envp_list **head, char **envp);
int			clear_envp_list(t_envp_list **head);
void		del_one_envp_list(t_envp_list **head, const char *key);
void		update_envp_list(t_envp_list **head, const char *k, const char *v);
void		get_key(t_envp_list *curr, const char *envp);
void		get_value(t_envp_list *curr, const char *envp);
char		**convert_envp_to_dptr(const t_envp_list *head);
t_envp_list	*get_sort_envp_list(t_envp_list *head);
t_envp_list	*find_list_by_key(t_envp_list *head, const char *key);
t_envp_list	*copy_envp_list(t_envp_list *head);
void		print_envp(t_envp_list *head, int op);

#endif
