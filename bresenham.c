/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 13:46:05 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	maxx(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(fdf->angle);
	*y = (*x + *y) * sin(fdf->angle) - z;
}

void	print_bresenham(float x, float y, float x2, float y2, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z2;
	int		color;

	if (fdf->palette == 0)
		color = fdf->color_matrix[(int)y][(int)x];
	if (fdf->palette == 1)
		color = 0x00ff00;

	z = fdf->int_matrix[(int)y][(int)x];
	z2 = fdf->int_matrix[(int)y2][(int)x2];
	z = z * fdf->z_escalar;
	z2 = z2 * fdf->z_escalar;

	x = x * fdf->zoom;
	y = y * fdf->zoom;
	x2 = x2 * fdf->zoom;
	y2 = y2 * fdf->zoom;

	if (fdf->perspective == 0)
	{
		isometric(&x, &y, z, fdf);
		isometric(&x2, &y2, z2, fdf);
	}

	x_step = x2 - x;
	y_step = y2 - y;
	max = maxx(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	x = x + fdf->move_x;
	y = y + fdf->move_y;
	x2 = x2 + fdf->move_x;
	y2 = y2 + fdf->move_y;
	while ((int )(x - x2) || (int )(y - y2))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, color);
		x += x_step;
		y += y_step;
	}
}
