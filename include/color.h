/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:02 by jaham             #+#    #+#             */
/*   Updated: 2022/03/22 12:16:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define PINK_BD "\001\033[1;38;5;219m\002"
# define RED "\001\033[1;38;5;203m\002"
# define PURPLE_BD "\001\033[1;38;5;147m\002"
# define BLUE_BT "\001\033[38;5;153m\002"
# define DEF_COL "\001\033[m\002"

//ESC[38:5:⟨n⟩m Select foreground color
//ESC[48:5:⟨n⟩m Select background color
//ESC[38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
//ESC[48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color

#endif