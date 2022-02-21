/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/21 13:20:35 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

void	draw_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			if (i < fdf->width - 1)
				print_bresenham(i, j, i + 1, j, fdf);
			if (j < fdf->height - 1)
				print_bresenham(i, j, i, j + 1, fdf);
			i++;
		}
		j++;
	}
}

int	deal_key(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 126)
		fdf->move_y -= 10;
	if (key == 125)
		fdf->move_y += 10;
	if (key == 124)
		fdf->move_x += 10;
	if (key == 123)
		fdf->move_x -= 10;
	if (key == 30)
		fdf->zoom += 2;
	if (key == 44)
		fdf->zoom -= 2;
	if (key == 35)
	{
		if (fdf->perspective == 0)
			fdf->perspective = 1;
		else
			fdf->perspective = 0;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_matrix(fdf);
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
	fdf->zoom = 25;
	return (fdf);
}

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	t_fdf			*fdf;

	i = 0;
	j = 0;
	fdf = init_struct();
	if (argc != 2)
		return (0);
	get_char_matrix(fdf, argv[1], &i);
	get_int_matrix(fdf, i);
	draw_matrix(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
