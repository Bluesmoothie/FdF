/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:51 by ygille            #+#    #+#             */
/*   Updated: 2024/11/17 18:49:39 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	window();
	exit(EXIT_SUCCESS);
}

t_mlx	window(void)
{
	t_mlx	mlx;

	mlx = mallox(sizeof(t_mlx));
	if (mlx == NULL)
		error(EMALLOC);
	mlx->mlx = mlx_init();
	if (mlx == NULL)
		error(EAGAIN);
	win = mlx_new_window(mlx, 512, 512, "FdF");
	if (win == NULL)
		error(EAGAIN);
	mlx_string_put(mlx, win, 100, 100, 0xCC00CC, "BONJOUR");
	mlx_key_hook(win, &key_hook, 0);
	mlx_loop(mlx);
}

int	quit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	error(int code)
{
	if (code >= 0)
	{
		errno = code;
		perror("");
	}
	else
	{
		if (code == EMALLOC)
			ft_putst
	exit(EXIT_FAILURE);
}
