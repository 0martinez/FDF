/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:55:55 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 12:55:59 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

t_fdf	*to_be_free(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->char_matrix[i] != 0)
	{
		free(fdf->char_matrix[i]);
		i++;
	}
	free(fdf->char_matrix);
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
	free(fdf->int_matrix);
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->color_matrix[i]);
		i++;
	}
	free(fdf->color_matrix);
	free(fdf);
	return (fdf);
}

void	leaks(void)
{
	system("leaks -q fdf");
}
