/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:22 by ygille            #+#    #+#             */
/*   Updated: 2024/11/17 19:51:47 by ygille           ###   ########.fr       */
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

//fdf.c
void	free_error(void *ptr, int code);
void	error(int code);
int		quit(void);

//mlx.c
t_mlx	*open_window(void);

//user_input.c
int		key_hook(int keycode, void *param);

//map.c
t_map	*retrieve_map(char *map);
int		open_map(char *map);
t_map	*parse_map(int fd);

#endif