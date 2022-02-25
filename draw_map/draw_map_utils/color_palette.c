/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:41:42 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 17:41:45 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

int	apply_palette(float y, float x, t_fdf *fdf)
{
	if (fdf->palette == 0)
		return (fdf->color_matrix[(int)y][(int)x]);
	else
		return (0x00ff00);
}
