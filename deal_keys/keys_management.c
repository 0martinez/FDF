/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:00:54 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 17:56:35 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	deal_key(int key, t_fdf *fdf)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
		handle_moves(key, fdf);
	if (key == 30 || key == 44)
		handle_zoom(key, fdf);
	if (key == 35)
		handle_perspective(key, fdf);
	if (key == 8)
		handle_palette(key, fdf);
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 12 || key == 13)
		handle_key_rotation(fdf, key);
	if (key == 53)
	{
		fdf = to_be_free(fdf);
		write(1, "EXIT SUCCES!\n", 13);
		exit (0);
	}
	draw_map_process(fdf);
	return (0);
}
