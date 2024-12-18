/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/18 17:56:38 by ygille           ###   ########.fr       */
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
** passing error code to error function
*/
void	free_error(t_mlx *mlx, t_map *map, int code)
{
	if (mlx)
	{
		close_window(mlx);
		free_mlx(mlx);
	}
	if (map)
		free_map(map);
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
	if (code > 0)
		perror("");
	else if (code == USAGE)
		ft_putstr_fd("Usage : ./fd map\n", 2);
	else if (code == MAP)
		ft_putstr_fd("Map error\n", 2);
	exit(EXIT_FAILURE);
}

/*
** Initialize the mlx structure with default values
*/
t_mlx	*init_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error(0);
	mlx->id = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_data = NULL;
	mlx->depth = DEPTH;
	mlx->size_line = WIDTH * 4;
	mlx->endian = ENDIAN;
	mlx->view.x_offset = OFFSET_X;
	mlx->view.y_offset = OFFSET_Y;
	mlx->view.center = 0;
	mlx->view.angle = ANGLE;
	mlx->view.zoom = 1;
	mlx->view.x_pos = 0;
	mlx->view.y_pos = 0;
	mlx->view.view_type = ISO;
	return (mlx);
}
