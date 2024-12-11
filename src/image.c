/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:05:15 by ygille            #+#    #+#             */
/*   Updated: 2024/12/11 15:45:15 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

int	view_calc(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (mlx->img == NULL)
		new_image(mlx);
	iso_view(mlx);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	return (0);
}
