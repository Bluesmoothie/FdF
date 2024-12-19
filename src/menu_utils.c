/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:48:21 by ygille            #+#    #+#             */
/*   Updated: 2024/12/19 12:03:38 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Return a string corresponding to the view mode
*/
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

/*
** Return a mapinfo structure
*/
t_mapinfo	get_mapinfo(t_mlx *mlx)
{
	t_mapinfo	map;
	char		*h_val;
	char		*w_val;
	char		*max_alt_val;

	h_val = ft_itoa(mlx->map->height);
	w_val = ft_itoa(mlx->map->width);
	max_alt_val = ft_itoa(mlx->map->max_altitude - 1);
	if (h_val == NULL || w_val == NULL || max_alt_val == NULL)
	{
		free_three(h_val, w_val, max_alt_val);
		free_error(mlx, mlx->map, -1);
	}
	map.height = ft_strjoin("Height: ", h_val);
	map.width = ft_strjoin("Width: ", w_val);
	map.max_alt = ft_strjoin("Max altitude: ", max_alt_val);
	free_three(h_val, w_val, max_alt_val);
	if (map.max_alt == NULL || map.height == NULL || map.width == NULL)
	{
		free_three(map.height, map.width, map.max_alt);
		free_error(mlx, mlx->map, -1);
	}
	return (map);
}
/*
** Free three strings securely
*/
void	free_three(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
}
