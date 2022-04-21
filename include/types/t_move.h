/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:08:17 by seunpark          #+#    #+#             */
/*   Updated: 2022/04/21 18:08:53 by seunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MOVE
# define T_MOVE

typedef enum e_move_direction	t_move_direction;

// 노드 순회 방향
enum e_move_direction
{
	RIGHT = 0,
	LEFT
};

#endif