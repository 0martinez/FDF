/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:50:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 12:50:31 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	apply_zoom(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x *= fdf->zoom;
	first->y *= fdf->zoom;
	second->x *= fdf->zoom;
	second->y *= fdf->zoom;
}
