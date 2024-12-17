/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:30:54 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT			2048
# define WIDTH			2048
# define DEPTH			32
# define ENDIAN			1
# define OFFSET_X		0
# define OFFSET_Y		0
# define ANGLE			0.52359877	

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_map
{
	int	height;
	int	width;
	int	max_altitude;
	int	**tab;
}	t_map;

typedef struct s_view_param
{
	int	zoom;
	int	x_offset;
	int	y_offset;
	int	center;
	int	angle;
	int	x_pos;
	int	y_pos;
	int	view_type;
}	t_view_param;

typedef struct s_mlx
{
	void			*id;
	void			*win;
	void			*img;
	int				*img_data;
	int				size_line;
	int				depth;
	int				endian;
	t_view_param	view;
	t_map			*map;
}	t_mlx;

typedef struct s_curve
{
	int	sx;
	int	sy;
	int	sz;
	int	ex;
	int	ey;
	int	ez;
}	t_curve;


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

//fdf.c
void			free_error(t_mlx *mlx, t_map *map, int code);
void			error(int code);

//axonometric.c
int				axo_x(int x, int z, t_mlx *mlx);
int				axo_y(int x, int y, int z, t_mlx *mlx);

//curve.c
void			draw_curve(t_mlx *mlx, t_curve curve);
void			verif_pos(t_mlx *mlx, int x, int y, int z);
void			bresenham(t_mlx *mlx, t_curve curve);
void			apply_view(t_mlx *mlx, t_curve *curve);

//curve_utils.c
void			n_curve(t_mlx *mlx, int sx, int sy);
void			w_curve(t_mlx *mlx, int sx, int sy);
void			e_curve(t_mlx *mlx, int sx, int sy);
void			s_curve(t_mlx *mlx, int sx, int sy);

//image.c
int				pixel_color(int t, int r, int g, int b);
int				gradient(int altitude, int max_altitude);
int				view_calc(void *param);
void			center(t_mlx *mlx, t_curve *curve);
void			apply_zoom(t_mlx *mlx, t_curve *curve);

//image_utils.c
void			put_center(t_mlx *mlx);
void			move_view(t_mlx *mlx, int keycode);
void			turn_view(t_mlx *mlx, int keycode);
void			display_center(t_mlx *mlx);
void			zoom_view(t_mlx *mlx, int button);

//isometric.c
int				iso_x(int x, int z, t_mlx *mlx);
int				iso_y(int x, int y, int z, t_mlx *mlx);
void			calc_view(t_mlx *mlx);

//map.c
t_map			*retrieve_map(char *map);
int				open_map(char *map);
void			get_map_size(t_map *map, char *map_file);
int				max_alt(char *line, int max);
t_map			*map_init(void);

//map_utils.c
int				calc_map_size(int fd);

//menu.c
void			display_menu(t_mlx *mlx);
char			*str_view_mode(int view_type);
void			display_controls(t_mlx *mlx);
void			display_settings(t_mlx *mlx);
void			display_mapinfo(t_mlx *mlx);

//mlx.c
t_mlx			*open_window(char *title, t_mlx *mlx);
void			input_wait(t_mlx *mlx);
void			new_image(t_mlx *mlx);
void			clear_img(t_mlx *mlx);
t_mlx			*init_struct(void);

//parse.c
void			parse_map_line(t_map *map, int fd, int line);

//user_input.c
int				key_hook(int keycode, void *param);
int				move_code(int keycode);
int				mouse_hook(int button, int x, int y, void *param);
int				destroy_hook(void *param);

// //test_grid.c
// void			draw_grid(t_mlx *mlx);
// void			draw_line(t_mlx *mlx, int sy, int sx, int ey, int ex, int color);
// void			td_grid(t_mlx *mlx);

// //tests.c
// int				test_image(void *param, int color);
// int				test_grid(void *param);
// void			fill_color(t_mlx *mlx, int color);

#endif