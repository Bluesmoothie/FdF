/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2025/01/07 13:43:11 by ygille           ###   ########.fr       */
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

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include "mlx.h"
# include "fdf_structs.h"
# include "fdf_enums.h"

//fdf.c
void		free_error(t_mlx *mlx, t_map *map, int code);
void		error(int code);
t_mlx		*init_struct(void);

//axonometric.c
int			axo_x(int x, int z);
int			axo_y(int x, int y, int z);

//bresenham.c
void		bresenham(t_mlx *mlx, t_curve curve);

//curves.c
void		n_curve(t_mlx *mlx, int sx, int sy);
void		w_curve(t_mlx *mlx, int sx, int sy);
void		e_curve(t_mlx *mlx, int sx, int sy);
void		s_curve(t_mlx *mlx, int sx, int sy);

//curves_utils.c
void		draw_curve(t_mlx *mlx, t_curve curve);
void		verif_pos(t_mlx *mlx, int x, int y, int z);
void		apply_view(t_mlx *mlx, t_curve *curve);
void		center(t_mlx *mlx);
void		apply_zoom(t_mlx *mlx, t_curve *curve);

//curves_utils_2.c
void		apply_angle(int *x, int *y, int angle);

//free.c
void		free_mlx(t_mlx *mlx);
void		free_map(t_map *map);

//image.c
int			frame_calc(void *param);
int			view_changed(t_view_param view, t_view_param old_view);
void		img_compute(t_mlx *mlx);

//image_utils.c
void		put_center(t_mlx *mlx);
int			pixel_color(int t, int r, int g, int b);
int			gradient(int altitude, int max_altitude);

//isometric.c
int			iso_x(int x, int z);
int			iso_y(int x, int y, int z);

//map.c
t_map		*retrieve_map(char *map);
void		get_map(t_map *map, char *map_file);

//map_utils.c
int			open_map(char *map, t_map *map_struct);
t_map		*map_init(void);
int			calc_map_size(int fd);
int			max_alt(char *line, int max);

//menu.c
void		display_menu(t_mlx *mlx);
void		display_controls(t_mlx *mlx);
void		display_settings(t_mlx *mlx);
void		display_mapinfo(t_mlx *mlx);

//menu_utils.c
char		*str_view_mode(int view_type);
t_mapinfo	get_mapinfo(t_mlx *mlx);
void		free_three(char *s1, char *s2, char *s3);

//mlx.c
t_mlx		*open_window(char *title, t_mlx *mlx);
void		input_wait(t_mlx *mlx);
void		new_image(t_mlx *mlx);
void		clear_img(t_mlx *mlx);
void		close_window(t_mlx *mlx);

//parse.c
void		parse_map_line(t_map *map, int fd, int line);

//user_input.c
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
int			destroy_hook(void *param);

//user_input_utils.c
void		move_view(t_mlx *mlx, int keycode);
void		turn_view(t_mlx *mlx, int keycode);
void		zoom_view(t_mlx *mlx, int button);
void		display_center(t_mlx *mlx);

#endif