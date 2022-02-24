/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_and_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:09:04 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 17:01:01 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	print_controls(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0x00ff00,
		"Move map: left | up | down | right");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0x00ff00, "Zoom: + | -");
	if (fdf->perspective == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00,
			"Change perspective to conic: P");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00,
			"Change perspective to isometric: P");
	if (fdf->palette == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00,
			"Change to matrix palette: C");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00,
			"Change to premade palette: C");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 100, 0x00ff00,
		"Rotate around x axis: Z / X");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 120, 0x00ff00,
		"Rotate around y axis: A / S");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 140, 0x00ff00,
		"Rotate around z axis: Q / W");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 160, 0x00ff00,
		"End program: ESC");
}

void	get_second_value(t_axes *first, t_axes *second, int flg)
{
	if (flg == FOR_X)
	{
		second->x = first->x + 1;
		second->y = first->y;
	}
	else
	{
		second->x = first->x;
		second->y = first->y + 1;
	}
}

void	draw_map(t_fdf *fdf)
{
	t_axes	first;
	t_axes	second;

	first.x = 0;
	first.y = 0;
	while (first.y < fdf->height)
	{
		first.x = 0;
		while (first.x < fdf->width)
		{
			if (first.x < fdf->width - 1)
			{
				get_second_value(&first, &second, FOR_X);
				print_bresenham(first, second, fdf);
			}
			if (first.y < fdf->height - 1)
			{
				get_second_value(&first, &second, FOR_Y);
				print_bresenham(first, second, fdf);
			}
			first.x++;
		}
		first.y++;
	}
	//print_controls(fdf);
}
