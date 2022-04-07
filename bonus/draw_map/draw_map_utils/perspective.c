/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:40:52 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:40:55 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	isometric(int z, t_fdf *fdf, t_axes *axe)
{
	axe->x = (axe->x - axe->y) * cos(fdf->angle);
	axe->y = (axe->x + axe->y) * sin(fdf->angle) - z;
}

void	apply_perspecive(t_fdf *fdf, t_axes *first, t_axes *second)
{
	if (fdf->perspective == 0)
	{
		isometric(first->z, fdf, first);
		isometric(second->z, fdf, second);
	}
}
