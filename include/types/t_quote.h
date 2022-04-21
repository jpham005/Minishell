/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_quote.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:55:40 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 20:32:53 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUOTE_H
# define T_QUOTE_H

typedef enum e_is_quoted		t_is_quoted;
typedef enum e_quote_mask		t_quote_mask;

enum e_is_quoted
{
	NOT_QUOTED = 0,
	QUOTED
};

enum e_quote_mask
{
	SQUOTE = 1 << 0,
	DQUOTE = 1 << 1
};

#endif