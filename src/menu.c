/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:23 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:21:16 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Display the menu by calling the display functions
*/
void	display_menu(t_mlx *mlx)
{
	display_controls(mlx);
	display_settings(mlx);
	display_mapinfo(mlx);
	mlx_string_put(mlx->id, mlx->win, 10, 2040, 0xFFFFFF, "ygille");
}

/*
** Display the controls on the window
*/
void	display_controls(t_mlx *mlx)
{
	mlx_string_put(mlx->id, mlx->win, 10, 10, 0xFFFFFF, "FDF");
	mlx_string_put(mlx->id, mlx->win, 10, 30, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(mlx->id, mlx->win, 10, 50, 0xFFFFFF, "Zoom: Scroll");
	mlx_string_put(mlx->id, mlx->win, 10, 70, 0xFFFFFF, "Change view: V");
	mlx_string_put(mlx->id, mlx->win, 10, 90, 0xFFFFFF, "Display center: X");
	mlx_string_put(mlx->id, mlx->win, 10, 110, 0xFFFFFF, "Rotate: E/Q");
	mlx_string_put(mlx->id, mlx->win, 10, 130, 0xFFFFFF, "Exit: ESC");
}

/*
** Display the settings on the window
*/
void	display_settings(t_mlx *mlx)
{
	char	*zoom;
	char	*viewmode;
	char	*zoom_val;

	zoom_val = ft_itoa(mlx->view.zoom);
	if (zoom_val == NULL)
		free_error(mlx, mlx->map, -1);
	zoom = ft_strjoin("Zoom: ", zoom_val);
	viewmode = ft_strjoin("View: ", str_view_mode(mlx->view.view_type));
	if (viewmode == NULL || zoom == NULL)
	{
		free_three(zoom, viewmode, zoom_val);
		free_error(mlx, mlx->map, -1);
	}
	mlx_string_put(mlx->id, mlx->win, 1900, 10, 0xFFFFFF, "Settings");
	mlx_string_put(mlx->id, mlx->win, 1900, 30, 0xFFFFFF, viewmode);
	mlx_string_put(mlx->id, mlx->win, 1900, 50, 0xFFFFFF, zoom);
	free_three(zoom, viewmode, zoom_val);
}

/*
** Display map info
*/
void	display_mapinfo(t_mlx *mlx)
{
	t_mapinfo	map;

	map = get_mapinfo(mlx);
	mlx_string_put(mlx->id, mlx->win, 1900, 1980, 0xFFFFFF, "Map info");
	mlx_string_put(mlx->id, mlx->win, 1900, 2000, 0xFFFFFF, map.height);
	mlx_string_put(mlx->id, mlx->win, 1900, 2020, 0xFFFFFF, map.width);
	mlx_string_put(mlx->id, mlx->win, 1900, 2040, 0xFFFFFF, map.max_alt);
	free_three(map.height, map.width, map.max_alt);
}
