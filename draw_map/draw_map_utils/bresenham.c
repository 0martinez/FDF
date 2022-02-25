/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:41:53 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:41:58 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	maxx(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void	bresenham(t_axes first, t_axes second, t_aux *src)
{
	src->x_step = second.x - first.x;
	src->y_step = second.y - first.y;
	src->max = maxx(mod(src->x_step), mod(src->y_step));
	src->x_step /= src->max;
	src->y_step /= src->max;
}
