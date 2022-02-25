/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:55:03 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 12:55:06 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_fdf.h"

void	rotate_x_exe(t_axes *first, t_axes *second, t_fdf *fdf)
{
	float	pre_y1;
	float	pre_y2;

	pre_y1 = first->y;
	pre_y2 = second->y;
	first->y = (first->y * cos(fdf->x_rot)) + (first->z * sin(fdf->x_rot));
	second->y = (second->y * cos(fdf->x_rot)) + (second->z * sin(fdf->x_rot));
	first->z = (-pre_y1 * sin(fdf->x_rot)) + (first->z * cos(fdf->x_rot));
	second->z = (-pre_y2 * sin(fdf->x_rot)) + (second->z * cos(fdf->x_rot));
}

void	rotate_y_exe(t_axes *first, t_axes *second, t_fdf *fdf)
{
	float	pre_x1;
	float	pre_x2;

	pre_x1 = first->x;
	pre_x2 = second->x;
	first->x = (first->x * cos(fdf->y_rot)) + (first->z * sin(fdf->y_rot));
	second->x = (second->x * cos(fdf->y_rot)) + (second->z * sin(fdf->y_rot));
	first->z = (-pre_x1 * sin(fdf->y_rot)) + (first->z * cos(fdf->y_rot));
	second->z = (-pre_x2 * sin(fdf->y_rot)) + (second->z * cos(fdf->y_rot));
}

void	rotate_z_exe(t_axes *first, t_axes *second, t_fdf *fdf)
{
	float	pre_x1;
	float	pre_x2;

	pre_x1 = first->x;
	pre_x2 = second->x;
	first->x = (first->x * cos(fdf->z_rot)) - (first->y * sin(fdf->z_rot));
	second->x = (second->x * cos(fdf->z_rot)) - (second->y * sin(fdf->z_rot));
	first->y = (pre_x1 * sin(fdf->z_rot)) + (first->y * cos(fdf->z_rot));
	second->y = (pre_x2 * sin(fdf->z_rot)) + (second->y * cos(fdf->z_rot));
}
