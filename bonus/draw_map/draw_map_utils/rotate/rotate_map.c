/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:42:18 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:42:21 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_fdf.h"

void	apply_rotation(t_axes *first, t_axes *second, t_fdf *fdf)
{
	rotate_x_exe(first, second, fdf);
	rotate_y_exe(first, second, fdf);
	rotate_z_exe(first, second, fdf);
}
