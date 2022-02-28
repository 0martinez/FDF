/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/28 13:50:21 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

struct s_fdf	*init_struct(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	fdf->height = 0;
	fdf->width = 0;
	fdf->move_x = 500;
	fdf->move_y = 200;
	fdf->perspective = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1950, 1080, "FDF");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1950, 1080);
	fdf->img_addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	fdf->zoom = 2;
	fdf->angle = 1;
	fdf->rotation = 0;
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->z_escalar = 1;
	fdf->palette = 0;
	fdf->selected_axis = 0;
	fdf->exit = 0;
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Incorrect number of arguments", 29);
		return (0);
	}
	fdf = init_struct();
	get_maps(fdf, argv[1]);
	draw_map(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_mouse_hook(fdf->win_ptr, mouse_hook, fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	print_controls(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
