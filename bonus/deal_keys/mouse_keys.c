/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:45:21 by omartine          #+#    #+#             */
/*   Updated: 2022/03/01 13:36:52 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	handle_z_scalar(int key, t_fdf *fdf)
{
	if (key == 4)
	{
		if ((fdf->z_escalar * 1.2) < 150)
			fdf->z_escalar *= 1.2;
	}
	if (key == 5)
	{
		if ((fdf->z_escalar * 0.8) > 0.001)
			fdf->z_escalar *= 0.8;
	}
}

int	mouse_hook(int key, int x, int y, t_fdf *fdf)
{
	if (key == 4 || key == 5)
		handle_z_scalar(key, fdf);
	x = 0;
	y = 0;
	draw_map_process(fdf);
	return (0);
}
