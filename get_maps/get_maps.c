/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:03:11 by omartine          #+#    #+#             */
/*   Updated: 2022/02/21 15:03:27 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	get_maps(t_fdf *fdf, char *str)
{
	int	i;

	i = 0;
	get_char_matrix(fdf, str, &i);
	get_int_matrix(fdf, i);
}
