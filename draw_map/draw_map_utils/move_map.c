/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:41:36 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:41:37 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	move_map(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x += fdf->move_x;
	first->y += fdf->move_y;
	second->x += fdf->move_x;
	second->y += fdf->move_y;
}
