/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/21 18:32:21 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

void	draw_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0x00ff00, "move map: left | up | down | right");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0x00ff00, "zoom: + | -");
	if (fdf->perspective == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00, "change perspective to conic: p");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00, "change perspective to isometric: p");
	if (fdf->palette == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00, "change to matrix palete: c");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00, "change to premade palete: c");
	while (j < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			if (i < fdf->width - 1)
				print_bresenham(i, j, i + 1, j, fdf);
			if (j < fdf->height - 1)
				print_bresenham(i, j, i, j + 1, fdf);
			i++;
		}
		j++;
	}
}

int	mouse_hook(int key, int x, int y, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 4)
		fdf->z_escalar *= 1.2;
	if (key == 5)
		fdf->z_escalar *= 0.8;
	x = 0;
	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_matrix(fdf);
	return (0);
}

int	deal_key(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 126)
		fdf->move_y -= 50;
	if (key == 125)
		fdf->move_y += 50;
	if (key == 124)
		fdf->move_x += 50;
	if (key == 123)
		fdf->move_x -= 50;
	if (key == 30)
		fdf->zoom += 2;
	if (key == 44)
		fdf->zoom -= 2;
	if (key == 35)
	{
		if (fdf->perspective == 0)
			fdf->perspective = 1;
		else
			fdf->perspective = 0;
	}
	if (key == 8)
	{
		if (fdf->palette == 0)
			fdf->palette = 1;
		else
			fdf->palette = 0;
	}
	//z6 x7 y16
	//r15 l37

	/*
	if (fdf->axe == 0)
	{
		if (key == 15)
		{
			fdf->x_rot = x;
			fdf->y_rot = y * cos(θ) - z * sin(θ);
			fdf->z_rot = y * sin(θ) + z * cos(θ);
		}
		if (key == 37)
		{

		}
	}
	else if (fdf->axe == 1)
	{

	}
	else if (fdf->axe == 2)
	{

	}
	else
		fdf->rotation = OFF;*/
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_matrix(fdf);
	return (0);
}

struct s_fdf	*init_struct(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	fdf->height = 0;
	fdf->width = 0;
	fdf->move_x = 500;
	fdf->move_y = 200;
	fdf->perspective = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "first_try");
	fdf->zoom = 25;
	fdf->angle = 1;
	fdf->rotation = 0;
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->z_escalar = 1;
	fdf->palette = 1;
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_fdf	*fdf;

	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	fdf = init_struct();
	get_maps(fdf, argv[1]);
	draw_matrix(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_mouse_hook(fdf->win_ptr, mouse_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
