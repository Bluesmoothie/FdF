/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 20:58:08 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EMALLOC		-1
# define HEIGHT			2048
# define WIDTH			2048
# define DEPTH			32
# define ENDIAN			1
# define OFFSET_X		200
# define OFFSET_Y		50
# define ANGLE			1.46373398

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
	int	zoom;
}	t_map;

typedef struct s_mlx
{
	void	*id;
	void	*win;
	void	*img;
	int		*img_data;
	int		size_line;
	int		depth;
	int		endian;
	t_map	*map;
}	t_mlx;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	NO_EVENT = 0L,
	KEY_PRESS = 1L<<0,
	KEY_RELEASE = 1L<<1,
	BUTTON_PRESS = 1L<<2,
	BUTTON_RELEASE = 1L<<3
};

//fdf.c
void			free_error(t_mlx *mlx, t_map *map, int code);
void			error(int code);
int				quit(t_mlx *mlx);

//mlx.c
t_mlx			*open_window(char *title, t_mlx *mlx);
void			input_wait(t_mlx *mlx);
void			new_image(t_mlx *mlx);
t_mlx			*init_struct(void);

//user_input.c
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				destroy_hook(void *param);

//map.c
t_map			*retrieve_map(char *map);
int				open_map(char *map);
void			get_map_size(t_map *map, char *map_file);
t_map			*map_init(void);
int				max_alt(char *line, int max);

//map2.c
void			parse_map_line(t_map *map, int fd, int line);

//image.c
int				pixel_color(int t, int r, int g, int b);
int				gradient(int altitude, int max_altitude);
int				test_image(void *param, int color);
void			fill_color(t_mlx *mlx, int color);
int				test_grid(void *param);

//grid.c
void			draw_grid(t_mlx *mlx);
void			draw_line(t_mlx *mlx, int sy, int sx, int ey, int ex, int color);
void			td_grid(t_mlx *mlx);

//isometric.c
int				iso_x(int x, int y);
int				iso_y(int x, int y, int z);

#endif