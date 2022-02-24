/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/23 20:06:07 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

int	mouse_hook(int key, int x, int y, t_fdf *fdf)
{
	if (key == 4)
		fdf->z_escalar *= 1.2;
	if (key == 5)
		fdf->z_escalar *= 0.8;
	x = 0;
	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	return (0);
}

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
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "first_try");
	fdf->zoom = 2;
	fdf->angle = 1;
	fdf->rotation = 0;
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->z_escalar = 1;
	fdf->palette = 1;
	fdf->selected_axis = 0;
	return (fdf);
}



int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (0);
	fdf = init_struct();
	get_maps(fdf, argv[1]);
	draw_map(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_mouse_hook(fdf->win_ptr, mouse_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	free(fdf);

	return (0);
}

/*rot_x(vars, &point.y, &point.z);
	rot_y(vars, &point.x, &point.z);
	rot_z(vars, &point.x, &point.y);
	isometric(vars, &point.x, &point.y, point.z);*/
