/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:51:09 by ygille           ###   ########.fr       */
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
** if an error occurs
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
	if (errno > 0)
		perror("");
	else if (errno == -1)
		ft_putstr_fd("Usage : ./fd map\n", 2);
	else if (errno == -2)
		ft_putstr_fd("Map error\n", 2);
	exit(EXIT_FAILURE);
}
