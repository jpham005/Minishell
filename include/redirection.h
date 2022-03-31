/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:20:18 by jaham             #+#    #+#             */
/*   Updated: 2022/03/31 18:05:30 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "parser.h"

# define IS_REDIR REDIR_IN | REDIR_HEREDOC | REDIR_OUT | REDIR_APPEND

#endif
