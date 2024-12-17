/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:54:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 18:36:06 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct s_view_param
{
	int				zoom;
	int				x_offset;
	int				y_offset;
	int				center;
	int				angle;
	int				x_pos;
	int				y_pos;
	int				view_type;
}	t_view_param;

typedef struct s_map
{
	int				height;
	int				width;
	int				max_altitude;
	int				**tab;
}	t_map;

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
	int				sx;
	int				sy;
	int				sz;
	int				ex;
	int				ey;
	int				ez;
}	t_curve;

#endif