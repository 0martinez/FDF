/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 12:49:34 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	get_z_value(t_fdf *fdf, t_axes *first, t_axes *second)
{
	first->z = fdf->int_matrix[(int)first->y][(int)first->x];
	second->z = fdf->int_matrix[(int)second->y][(int)second->x];
	first->z *= fdf->z_escalar;
	second->z *= fdf->z_escalar;
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
	move_map(&first, &second, fdf);
	while ((int )(first.x - second.x) || (int )(first.y - second.y))
	{
		if ((first.x > 0 && first.x < 1950) && (first.y > 0 && first.y < 1080))
			my_mlx_pixel_put(fdf, first.x, first.y, src.color);
		first.x += src.x_step;
		first.y += src.y_step;
	}
}
