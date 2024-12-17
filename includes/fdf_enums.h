/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:57:07 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:57:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ENUMS_H
# define FDF_ENUMS_H

// Mlx events codes and masks
enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_events_mask
{
	NO_EVENT = 0L,
	KEY_PRESS = 1L<<0,
	KEY_RELEASE = 1L<<1,
	BUTTON_PRESS = 1L<<2,
	BUTTON_RELEASE = 1L<<3
};

enum e_keycode
{
	A_LEFT = 65361,
	A_RIGHT = 65363,
	A_UP = 65362,
	A_DOWN = 65364,
	ESC = 65307,
	KEY_X = 120,
	KEY_Q = 113,
	KEY_E = 101,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_V = 118,
	KEY_T = 116,
	KEY_G = 103
};

enum e_mousecode
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

enum e_view_types
{
	ISO = 0,
	AXO = 1,
	DD = 2
};

enum e_error_codes
{
	NO_ERROR = 0,
	USAGE = -1,
	MAP = -2
};

#endif