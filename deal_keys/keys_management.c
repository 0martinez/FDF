/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:00:54 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 18:35:06 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	deal_key(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 126 || key == 125 || key == 124 || key == 123)
		handle_moves(key, fdf);
	if (key == 30 || key == 44)
		handle_zoom(key, fdf);
	if (key == 35)
		handle_perspective(key, fdf);
	if (key == 8)
		handle_palette(key, fdf);
	if (key == 7 || key == 6)
		handle_rotation(key, fdf);
	if (key == 53)
		exit (0);
	if (key == 7 || key == 6 || key == 'y')
	{
	
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_matrix(fdf);
	return (0);
}
