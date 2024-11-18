/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:51 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 12:26:25 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_map	*map;

	if (argc != 2)
		error(-1);
	map = retrieve_map(argv[1]);
	(void) map;
	mlx = open_window(argv[1]);
	input_wait(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
}

int	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->id, mlx->win);
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_error(void *ptr, int code)
{
	free(ptr);
	error(code);
}

void	error(int code)
{
	if (code)
		errno = code;
	if (errno > 0)
		perror("");
	else if (errno == -1)
		ft_putstr_fd("Usage : ./fd map\n", 2);
	exit(EXIT_FAILURE);
}
