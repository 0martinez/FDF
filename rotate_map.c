/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:15:00 by omartine          #+#    #+#             */
/*   Updated: 2022/02/08 17:37:59 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

void	rotate_matrix(int **int_matrix, t_fdf *fdf)
{
	int	row;
	int	height;
	int	width;
	int	col;
	int	prev;
	int	curr;
	int	i;

	height = fdf->height;
	width = fdf->width;
	row = 0;
	col = 0;
	while (row < height && col < width)
	{
		if (row + 1 == height || col + 1 == width)
			break ;
		prev = fdf->int_matrix[row + 1][col];
		i = col;
		while (i < width)
		{
			curr = fdf->int_matrix[row][i];
			fdf->int_matrix[row][i] = prev;
			prev = curr;
			i++;
		}
		row++;
		i = row;
		while (i < height)
		{
			curr = fdf->int_matrix[i][width - 1];
			fdf->int_matrix[i][width - 1] = prev;
			prev = curr;
			i++;
		}
		width--;
		if (row < height)
		{
			i = width - 1;
			while (i >= col)
			{
				curr = fdf->int_matrix[height - 1][i];
				fdf->int_matrix[height - 1][i] = prev;
				prev = curr;
				i--;
			}
		}
		height--;
		if (col < width)
		{
			i = height - 1;
			while (i >= row)
			{
				curr = fdf->int_matrix[i][col];
				fdf->int_matrix[i][col] = prev;
				prev = curr;
				i--;
			}
		}
		col++;
	}
}
