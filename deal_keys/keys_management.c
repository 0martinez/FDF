/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:00:54 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 17:58:32 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	leaks(void)
{
	system("leaks -q fdf");
}

t_fdf	*to_be_free(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->char_matrix[i] != 0)
	{
		free(fdf->char_matrix[i]);
		i++;
	}
	free(fdf->char_matrix);
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
	free(fdf->int_matrix);
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->color_matrix[i]);
		i++;
	}
	free(fdf->color_matrix);
	free(fdf);
	return (fdf);
}

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
		atexit(leaks);
		exit (0);
	}
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1950, 1080);
		fdf->img_addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	print_controls(fdf);
	return (0);
}
