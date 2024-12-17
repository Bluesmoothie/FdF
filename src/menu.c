/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:23 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:18:07 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	display_menu(t_mlx *mlx)
{
	display_controls(mlx);
	display_settings(mlx);
	display_mapinfo(mlx);
	mlx_string_put(mlx->id, mlx->win, 10, 2040, 0xFFFFFF, "ygille");
}

char	*str_view_mode(int view_type)
{
	if (view_type == ISO)
		return ("3D Isometric");
	else if (view_type == AXO)
		return ("3D Axonometric");
	else if (view_type == DD)
		return ("2D");
	return ("Unknown");
}

void	display_controls(t_mlx *mlx)
{
	mlx_string_put(mlx->id, mlx->win, 10, 10, 0xFFFFFF, "FDF");
	mlx_string_put(mlx->id, mlx->win, 10, 30, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(mlx->id, mlx->win, 10, 50, 0xFFFFFF, "Zoom: Scroll");
	mlx_string_put(mlx->id, mlx->win, 10, 70, 0xFFFFFF, "Change view: V");
	mlx_string_put(mlx->id, mlx->win, 10, 90, 0xFFFFFF, "Display center: X");
	mlx_string_put(mlx->id, mlx->win, 10, 110, 0xFFFFFF, "Exit: ESC");
}

void	display_settings(t_mlx *mlx)
{
	char	*zoom;
	char	*viewmode;
	char	*zoom_val;

	zoom_val = ft_itoa(mlx->view.zoom);
	zoom = ft_strjoin("Zoom: ", zoom_val);
	viewmode = ft_strjoin("View: ", str_view_mode(mlx->view.view_type));
	if (viewmode == NULL || zoom == NULL)
		free_error(mlx, mlx->map, -1);
	mlx_string_put(mlx->id, mlx->win, 1900, 10, 0xFFFFFF, "Settings");
	mlx_string_put(mlx->id, mlx->win, 1900, 30, 0xFFFFFF, viewmode);
	mlx_string_put(mlx->id, mlx->win, 1900, 50, 0xFFFFFF, zoom);
	free(zoom);
	free(viewmode);
	free(zoom_val);
}

void	display_mapinfo(t_mlx *mlx)
{
	char	*height;
	char	*width;
	char	*max_alt;
	char	*height_val;
	char	*width_val;
	char	*max_alt_val;

	height_val = ft_itoa(mlx->map->height);
	width_val = ft_itoa(mlx->map->width);
	max_alt_val = ft_itoa(mlx->map->max_altitude - 1);
	height = ft_strjoin("Height: ", height_val);
	width = ft_strjoin("Width: ", width_val);
	max_alt = ft_strjoin("Max altitude: ", max_alt_val);
	if (max_alt == NULL || height == NULL || width == NULL)
		free_error(mlx, mlx->map, -1);
	mlx_string_put(mlx->id, mlx->win, 1900, 1980, 0xFFFFFF, "Map info");
	mlx_string_put(mlx->id, mlx->win, 1900, 2000, 0xFFFFFF, height);
	mlx_string_put(mlx->id, mlx->win, 1900, 2020, 0xFFFFFF, width);
	mlx_string_put(mlx->id, mlx->win, 1900, 2040, 0xFFFFFF, max_alt);
	free(height);
	free(width);
	free(max_alt);
	free(height_val);
	free(width_val);
	free(max_alt_val);
}
