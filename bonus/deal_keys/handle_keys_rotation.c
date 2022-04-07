/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:58:17 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 13:03:28 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	handle_key_rotation(t_fdf *fdf, int key)
{
	if (key == 0)
		fdf->x_rot -= 0.05;
	if (key == 1)
		fdf->x_rot += 0.05;
	if (key == 6)
		fdf->y_rot += 0.05;
	if (key == 7)
		fdf->y_rot -= 0.05;
	if (key == 12)
		fdf->z_rot += 0.05;
	if (key == 13)
		fdf->z_rot -= 0.05;
}
