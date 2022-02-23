/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_and_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:09:04 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 18:59:19 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	print_controls(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0x00ff00,
		"move map: left | up | down | right");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0x00ff00, "zoom: + | -");
	if (fdf->perspective == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00,
			"change perspective to conic: p");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00ff00,
			"change perspective to isometric: p");
	if (fdf->palette == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00,
			"change to matrix palette: c");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00ff00,
			"change to premade palette: c");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 100, 0x00ff00,
		"end program: ESC");
}

void	draw_matrix(t_fdf *fdf)
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
				second.x = first.x + 1;
				second.y = first.y;
				print_bresenham(first, second, fdf);
			}
			if (first.y < fdf->height - 1)
			{
				second.x = first.x;
				second.y = first.y + 1;
				print_bresenham(first, second, fdf);
			}
			first.x++;
		}
		first.y++;
	}
	print_controls(fdf);
}
