/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:30 by omartine         ###   ########.fr       */
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

void	get_z_value(t_fdf *fdf, t_axes *first, t_axes *second)
{
	first->z = fdf->int_matrix[(int)first->y][(int)first->x];
	second->z = fdf->int_matrix[(int)second->y][(int)second->x];
	first->z *= fdf->z_escalar;
	second->z *= fdf->z_escalar;
}

void	apply_zoom(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x *= fdf->zoom;
	first->y *= fdf->zoom;
	second->x *= fdf->zoom;
	second->y *= fdf->zoom;
}

void	apply_perspecive(t_fdf *fdf, t_axes *first, t_axes *second)
{
	if (fdf->perspective == 0)
	{
		isometric(first->z, fdf, first);
		isometric(second->z, fdf, second);
	}
}

void	bresenham(t_axes first, t_axes second, t_aux *src)
{
	src->x_step = second.x - first.x;
	src->y_step = second.y - first.y;
	src->max = maxx(mod(src->x_step), mod(src->y_step));
	src->x_step /= src->max;
	src->y_step /= src->max;
}

void	move_object(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x += fdf->move_x;
	first->y += fdf->move_y;
	second->x += fdf->move_x;
	second->y += fdf->move_y;
}

void	apply_rotation(t_axes *first, t_axes *second, t_fdf *fdf)
{
	rotate_x_exe(first, second, fdf);
	rotate_y_exe(first, second, fdf);
	rotate_z_exe(first, second, fdf);
}

void	my_mlx_pixel_put(t_fdf *fdf, float x, float y, int color)
{
	char	*dst;

	dst = fdf->img_addr + ((int)y * fdf->line_length + (int)x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_bresenham(t_axes first, t_axes second, t_fdf *fdf)
{
	t_aux	src;

	src.color = apply_palette(first.y, first.x, fdf);
	get_z_value(fdf, &first, &second);
	apply_zoom(&first, &second, fdf);
	apply_rotation(&first, &second, fdf);
	apply_perspecive(fdf, &first, &second);
	bresenham(first, second, &src);
	move_object(&first, &second, fdf);
	while ((int )(first.x - second.x) || (int )(first.y - second.y))
	{
		if ((first.x > 0 && first.x < 1950) && (first.y > 0 && first.y < 1080))
			my_mlx_pixel_put(fdf, first.x, first.y, src.color);
		first.x += src.x_step;
		first.y += src.y_step;
	}
}
