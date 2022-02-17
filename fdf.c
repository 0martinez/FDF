/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/17 17:27:38 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

struct s_fdf	init_struct(void)
{
	t_fdf	fdf;

	fdf.height = 0;
	fdf.width = 0;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "first_try");
	fdf.zoom = 25;
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	//int		aux_width;
	t_fdf	fdf;

	i = 0;
	j = 0;
	fdf = init_struct();
	if (argc != 2)
		return (0);
	fdf = get_char_matrix(fdf, argv[1], &i);
	fdf = get_int_matrix(fdf, i);
	j = 0;
	i = 0;
	while (j < fdf.height)
	{
		i = 0;
		while (i < fdf.width)
		{
			if (i < fdf.width - 1)
				print_bresenham(i, j, i + 1, j, &fdf);
			if (j < fdf.height - 1)
				print_bresenham(i, j, i, j + 1, &fdf);
			i++;
		}
		j++;
	}
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
