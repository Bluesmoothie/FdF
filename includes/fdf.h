/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 16:01:30 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EMALLOC		-1
# define HEIGHT			512
# define WIDTH			512
# define DEPTH			32
# define ENDIAN			1

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

typedef struct s_mlx
{
	void	*id;
	void	*win;
	void	*img;
	int		*img_data;
	int		size_line;
	int		depth;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	int	height;
	int	width;
	int	max_altitude;
	int	**tab;
}	t_map;

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
void	free_error(t_mlx *mlx, int code);
void	error(int code);
int		quit(t_mlx *mlx);

//mlx.c
t_mlx	*open_window(char *title);
void	input_wait(t_mlx *mlx);
void	new_image(t_mlx *mlx);
t_mlx	*init_struct();

//user_input.c
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		destroy_hook(void *param);

//map.c
t_map	*retrieve_map(char *map);
int		open_map(char *map);
t_map	*parse_map(int fd);

//image.c
int		pixel_color(int t, int r, int g, int b);
int		test_image(void *param, int color);
void	fill_color(t_mlx *mlx, int color);

#endif