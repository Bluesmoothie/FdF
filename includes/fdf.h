/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 12:18:04 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EMALLOC	-1

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
void	free_error(void *ptr, int code);
void	error(int code);
int		quit(t_mlx *mlx);

//mlx.c
t_mlx	*open_window(void);
void	input_wait(t_mlx *mlx);

//user_input.c
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		destroy_hook(void *param);

//map.c
t_map	*retrieve_map(char *map);
int		open_map(char *map);
t_map	*parse_map(int fd);

//color.c
int		pixel_color(int t, int r, int g, int b);

#endif