/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_and_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:09:04 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 13:09:55 by omartine         ###   ########.fr       */
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
}

void	draw_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	print_controls(fdf);
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
