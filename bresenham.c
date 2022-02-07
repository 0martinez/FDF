/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/07 18:29:44 by omartine         ###   ########.fr       */
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

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	print_bresenham(float x, float y, float x2, float y2, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z2;
	//char	*color;

	z = fdf->int_matrix[(int)y][(int)x];
	z2 = fdf->int_matrix[(int)y2][(int)x2];
	x = x * fdf->zoom;
	y = y * fdf->zoom;
	x2 = x2 * fdf->zoom;
	y2 = y2 * fdf->zoom;


	isometric(&x, &y, z);
	isometric(&x2, &y2, z2);
	x_step = x2 - x;
	y_step = y2 - y;
	max = maxx(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	x += 300;
	y += 300;
	x2 += 300;
	y2 += 300;
	printf("---\n");
	while ((int )(x - x2) || (int )(y - y2))
	{
		printf("<%f><%f>\n", x, y);
		printf("<%f><%f>\n", x_step, y_step);
		printf("<%d><%d>\n", (int)(x - x2), (int)(y - y2));
		if (z != 0 || z2 != 0)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, 0x00ff00);
		else
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )x, (int )y, 0xff0000);
		x += x_step;
		y += y_step;
	}
}
