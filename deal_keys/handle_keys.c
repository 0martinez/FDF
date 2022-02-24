/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:04:01 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 16:42:31 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	handle_moves(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->move_y -= 50;
	if (key == 125)
		fdf->move_y += 50;
	if (key == 124)
		fdf->move_x += 50;
	if (key == 123)
		fdf->move_x -= 50;
}

void	handle_zoom(int key, t_fdf *fdf)
{
	if (key == 30)
		fdf->zoom += 2;
	if (key == 44)
	{
		if (fdf->zoom - 2 > 0)
			fdf->zoom -= 2;
	}
}

void	handle_perspective(int key, t_fdf *fdf)
{
	if (key == 35)
	{
		if (fdf->perspective == 0)
		{
			fdf->perspective = 1;
			fdf->x_rot = 0;
			fdf->y_rot = 0;
			fdf->z_rot = 0;
		}
		else
			fdf->perspective = 0;
	}
}

void	handle_palette(int key, t_fdf *fdf)
{
	if (key == 8)
	{
		if (fdf->palette == 0)
			fdf->palette = 1;
		else
			fdf->palette = 0;
	}
}

void	handle_rotation(int key, t_fdf *fdf)
{
	if (key == 7)
	{
		fdf->rotation = ON;
		fdf->angle += 0.05;
	}
	if (key == 6)
	{
		fdf->rotation = ON;
		fdf->angle -= 0.05;
	}
}
