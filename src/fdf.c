/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 12:42:47 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
		error(-1);
	mlx = init_struct();
	mlx->map = retrieve_map(argv[1]);
	mlx = open_window(argv[1], mlx);
	input_wait(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
}

/*
** Safely free the mlx and map structures and exit the program
*/
int	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->id, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->id, mlx->img);
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** Safely free the mlx and map structures and exit the program
** if an error occurs
*/
void	free_error(t_mlx *mlx, t_map *map, int code)
{
	int	i;

	i = -1;
	if (mlx != NULL)
	{
		mlx_destroy_window(mlx->id, mlx->win);
		if (mlx->img)
			mlx_destroy_image(mlx->id, mlx->img);
		free(mlx);
	}
	if (map != NULL)
	{
		if (map->tab != NULL)
		{
			while (map->tab[++i] != NULL)
				free(map->tab[i]);
			free(map->tab);
		}
		free(map);
	}
	error(code);
}

/*
** Print an error message and exit the program
** Support custom error codes
*/
void	error(int code)
{
	if (code)
		errno = code;
	if (errno > 0)
		perror("");
	else if (errno == -1)
		ft_putstr_fd("Usage : ./fd map\n", 2);
	else if (errno == -2)
		ft_putstr_fd("Map error\n", 2);
	exit(EXIT_FAILURE);
}
