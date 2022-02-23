/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 20:26:46 by omartine         ###   ########.fr       */
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

void	isometric(int z, t_fdf *fdf, t_axes *axe)
{
	axe->x = (axe->x - axe->y) * cos(fdf->angle);
	axe->y = (axe->x + axe->y) * sin(fdf->angle) - z;
}

int	apply_palette(float y, float x, t_fdf *fdf)
{
	if (fdf->palette == 0)
		return (fdf->color_matrix[(int)y][(int)x]);
	else
		return (0x00ff00);
}

void	get_z_value(t_aux *src, t_fdf *fdf, t_axes first, t_axes second)
{
	src->z = fdf->int_matrix[(int)first.y][(int)first.x];
	src->z2 = fdf->int_matrix[(int)second.y][(int)second.x];
	src->z = src->z * fdf->z_escalar;
	src->z2 = src->z2 * fdf->z_escalar;
}

void	apply_zoom(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x *= fdf->zoom;
	first->y *= fdf->zoom;
	second->x *= fdf->zoom;
	second->y *= fdf->zoom;
}

void	apply_perspecive(t_fdf *fdf, t_axes *first, t_axes *second, t_aux *src)
{
	if (fdf->perspective == 0)
	{
		isometric(src->z, fdf, first);
		isometric(src->z2, fdf, second);
	}
}



void	print_bresenham(t_axes first, t_axes second, t_fdf *fdf)
{
	t_aux	src;

	src.color = apply_palette(first.y, first.x, fdf);
	get_z_value(&src, fdf, first, second);
	apply_zoom(&first, &second, fdf);
	apply_perspecive(fdf, &first, &second, &src);

	src.x_step = second.x - first.x;
	src.y_step = second.y - first.y;
	src.max = maxx(mod(src.x_step), mod(src.y_step));
	src.x_step /= src.max;
	src.y_step /= src.max;

	first.x = first.x + fdf->move_x;
	first.y = first.y + fdf->move_y;
	second.x = second.x + fdf->move_x;
	second.y = second.y + fdf->move_y;
	while ((int )(first.x - second.x) || (int )(first.y - second.y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int )first.x, (int )first.y, src.color);
		first.x += src.x_step;
		first.y += src.y_step;
	}
}
