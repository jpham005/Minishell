/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:02 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 22:20:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED "\001\033[38;5;203m\002"
# define RED_BD "\001\033[1;38;5;203m\002"
# define RED_BT "\001\033[38;5;210m\002"
# define ORANGE "\001\033[38;5;214m\002"
# define YELLOW_BT_BD "\001\033[38;5;221m\002"
# define DEF_COL "\001\033[m\002"

//ESC[38:5:⟨n⟩m Select foreground color
//ESC[48:5:⟨n⟩m Select background color
//ESC[38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
//ESC[48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color

#endif