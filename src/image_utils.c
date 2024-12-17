/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:03:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:34:39 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Put a cross in the center of the window
*/
void	put_center(t_mlx *mlx)
{
	int	i;

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
