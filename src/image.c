/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:05:15 by ygille            #+#    #+#             */
/*   Updated: 2024/12/09 16:28:14 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Calculate the pixel color for mlx
*/
int	pixel_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
** Calculate the pixel gradient
*/
int	gradient(int altitude, int max_altitude)
{
	int	r;
	int	g;
	int	b;

	r = (255 * altitude) / max_altitude;
	g = (255 * (max_altitude - altitude)) / max_altitude;
	b = 128;
	return (pixel_color(0, r, g, b));
}

/*
** Display a test image
*/
int	test_image(void *param, int color)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (mlx->img == NULL)
		new_image(mlx);
	fill_color(mlx, color);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	return (0);
}

/*
** Display a test grid
*/
int	test_grid(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (mlx->img == NULL)
		new_image(mlx);
	td_grid(mlx);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	return (0);
}

/*
** Fill the image with a color
*/
void	fill_color(t_mlx *mlx, int color)
{
	int	i;
	int	*pixel;

	i = 0;
	pixel = mlx->img_data;
	while (i < HEIGHT * WIDTH)
	{
		*pixel = color;
		pixel++;
		i++;
	}
	return ;
}
