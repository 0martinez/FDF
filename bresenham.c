/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/19 17:50:08 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

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

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z;
}

void	print_bresenham(float x, float y, float x2, float y2, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z2;
	int		color;
	//float	angle;



	color = get_color(y, x, fdf);
	z = fdf->int_matrix[(int)y][(int)x];
	z2 = fdf->int_matrix[(int)y2][(int)x2];


	x = x * fdf->zoom;
	y = y * fdf->zoom;
	x2 = x2 * fdf->zoom;
	y2 = y2 * fdf->zoom;

	//angle = 90;
	//x = x * cos(angle) - y * sin(angle);
	//y = x * sin(angle) + y * cos(angle);
	//x2 = x2 * cos(angle) - y2 * sin(angle);
	//y2 = x2 * sin(angle) + y2 * cos(angle);

	if (fdf->perspective == 0)
	{
		isometric(&x, &y, z);
		isometric(&x2, &y2, z2);
	}


	x_step = x2 - x;
	y_step = y2 - y;
	max = maxx(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	x += 500;
	y += 200;
	x2 += 500;
	y2 += 200;
	while ((int )(x - x2) || (int )(y - y2))
	{
		/*if (z != 0 || z2 != 0)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, 0x00ff00);
		else
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, 0xff00ff);*/
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, color);
		x += x_step;
		y += y_step;
	}
}
