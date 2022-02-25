/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:41:02 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:41:27 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, float x, float y, int color)
{
	char	*dst;

	dst = fdf->img_addr + ((int)y * fdf->line_length
			+ (int)x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
