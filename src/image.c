/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student->42lyon->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:05:15 by ygille            #+#    #+#             */
/*   Updated: 2024/12/12 15:32:46 by ygille           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_center(t_mlx *mlx);

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
	g = 255 - r;
	b = 255 - r;
	return (pixel_color(0, r, g, b));
}

int	view_calc(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (mlx->img == NULL)
		new_image(mlx);
	put_center(mlx);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	iso_view(mlx);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	return (0);
}
void	center(t_mlx *mlx, t_curve *curve)
{
	curve->sx += (WIDTH - mlx->map->width) / 2;
	curve->sy += (HEIGHT - mlx->map->height) / 2;
	curve->ex += (WIDTH - mlx->map->width) / 2;
	curve->ey += (HEIGHT - mlx->map->height) / 2;
}

void	apply_zoom(t_mlx *mlx, t_curve *curve)
{
	(void)mlx;
	(void)curve;
}

void	put_center(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < HEIGHT - 1)
	{
		mlx->img_data[i + (WIDTH / 2) * WIDTH] = pixel_color(0, 255, 255, 255);
		i++;
	}
	i = 0;
	while (i < WIDTH - 1)
	{
		mlx->img_data[(HEIGHT / 2) + i * WIDTH] = pixel_color(0, 255, 255, 255);
		i++;
	}
}
